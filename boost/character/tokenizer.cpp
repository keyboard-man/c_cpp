/*************************************************************************
	> File Name: tokenizer.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年02月22日 星期一 11时10分41秒
 ************************************************************************/

#include <boost/tokenizer.hpp>
#include <string>
#include <cstring>
#include <iostream>

template<class T>
void print(T &tok)
{
	for(auto& x: tok)
	{
		std::cout << "[" << x << "]";
	}
	std::cout << std::endl;
}

int main()
{
	{
		std::string str("Link raise the master-sword.");

		boost::tokenizer<> tok(str);

		std::cout << "Origin string: " << str << std::endl;
		print(tok);
	}

	{
		//c_type string 
		char *c_str = "Link ;; <master-sword> zelda";
		boost::char_separator<char> sep;
		//change tokenizer template params to fit char_separator & c_type string
		boost::tokenizer<boost::char_separator<char>, char*> tok(c_str,c_str+strlen(c_str),sep);
		std::cout << "Origin string: " << c_str << std::endl;
		print(tok);

		//re-token
		//use " ;-<>" to separat the string, keep "<>" & drop " ;-"
		tok.assign(c_str,c_str+strlen(c_str),
				boost::char_separator<char>(" ;-","<>"));
		print(tok);

		//re-token
		//use " ;-<>" to separat the string, drop char_separator & keep empty words between char_separator
		tok.assign(c_str,c_str+strlen(c_str),
				boost::char_separator<char>(" ;-<>","",boost::keep_empty_tokens));
		print(tok);
	}

	{
		//escaped_list_separator is used to deal with CSV(Comma Separated Values) file
		std::string str = "id,100,name,\"mario\"";
		boost::escaped_list_separator<char> sep;
		boost::tokenizer<boost::escaped_list_separator<char> > tok(str,sep);
		std::cout << "Origin string: " << str << std::endl;
		print(tok);
	}

	{
		//offset_separator use strlen to separat the string
		//template <typename Iter>
		//offset_separator<Iter begin, Iter end, bool wrap_offsets = true,
		//				   bool return_partial_last = true);
		//wrap_offsets:			Token for the left letter?
		//return_partial_last:	Return the left letter?
		std::string str = "2233344445";
		int offsets[] = {2,3,4};
		boost::offset_separator sep(offsets,offsets+3,true,false);
		boost::tokenizer<boost::offset_separator> tok(str,sep);
		std::cout << "Origin string: " << str << std::endl;
		print(tok);
		str += "56667";
		//re-token
		tok.assign(str,boost::offset_separator(offsets,offsets+3,false));
		print(tok);
		//re-token
		tok.assign(str,boost::offset_separator(offsets,offsets+3,true,false));
		print(tok);
	}

	return 0;
}
