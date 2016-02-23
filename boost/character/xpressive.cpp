/*************************************************************************
	> File Name: xpressive.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年02月22日 星期一 16时02分22秒
 ************************************************************************/

#include <boost/xpressive/xpressive_dynamic.hpp>
#include <iostream>

//basic_regex
//template<typename BidiIter>
//struct basic_regex
//{
//	basic_regex();
//	basic_regex(basic_regex const &);
//	regex_id_type regex_id() const;
//	std::size_t mark_count() const;
//	void swap(basic_regex &);
//
//	static basic_regex
//	compile(InputRange const & pat);
//};
//
//typedef basic_regex<std::string::const_iterator> sregex;
//typedef basic_regex<char const *>				   cregex;

//template<typename BidiIter>
//struct match_results
//{
//	size_type size() const;
//	bool empty() const;
//	template<typename Sub>
//	const_reference operator[](Sub const & i) const;
//};
//typedef match_results<std::string::const_iterator> smatch;
//typedef match_results<char const *>				cmatch;

//template<typename BidiIter>
//struct sub_match : public std::pair<BidiIter,BidiIter>
//{
//	string_type str() const;
//	difference_type length() const;
//	bool operator!() const;
//	int compare(strirng_type const &) const;
//	bool matched;
//};

int main()
{
	using namespace boost::xpressive;
	//regex match
	{
		cregex reg = cregex::compile("a.c");

		assert(regex_match("abc",reg));
		assert(regex_match("a+c",reg));
		assert(!regex_match("ac",reg));
		assert(!regex_match("abd",reg));
	}

	{
		//C++11 raw string
		cregex reg = cregex::compile(
				R"(\d{6}(1|2)\d{3}(0|1)\d[0-3]\d\d{3}(X|\d))",icase);
		assert(regex_match("999555197001019999",reg));
		assert(regex_match("99955519700101999X",reg));
		assert(regex_match("99955520100101999x",reg));
		assert(!regex_match("99955519700101999z",reg));
		assert(!regex_match("99955530100101999X",reg));
		assert(!regex_match("99955520109901999X",reg));
	}

	{
		//C++98 string
		cregex reg = cregex::compile(
				"\\d{6}((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))",icase);
		cmatch what;
		assert(regex_match("999555199701019999",what,reg));
		for(auto x : what)
		{
			std::cout << "[" << x << "]";
		}
		std::cout << std::endl << "date:" << what[1] << "-" << what[3] << "-" << what[5] << std::endl;
	}

	//regex search
	{
		char* str = "there is a POWER-suit item";
		cregex reg = cregex::compile("(power)-(.{4})",icase);
		assert(regex_search(str,reg));
		cmatch what;
		regex_search(str,what,reg);
		assert(what.size()==3);

		std::cout << what[1] << what[2] << std::endl;
		assert(!regex_search("error message",reg));
	}

	//regex replace
	{
		std::string str("readme.txt");
		sregex reg1 = sregex::compile("(.*)(me)");
		sregex reg2 = sregex::compile("(t)(.)(t)");

		std::cout << regex_replace(str,reg1,"manual") << std::endl;
		std::cout << regex_replace(str,reg1,"$1you") << std::endl;
		std::cout << regex_replace(str,reg1,"$&$&") << std::endl;
		std::cout << regex_replace(str,reg2,"$1N$3") << std::endl;
		std::cout << regex_replace(str,reg2,"$1$3") << std::endl;
	}

	//regex iterator
	{
		std::string str("Power-bomb, power-suit, pOWER-beam all items\n");
		sregex reg = sregex::compile("power-(\\w{4})",icase);

		sregex_iterator pos(str.begin(),str.end(),reg);
		sregex_iterator end;
		while(pos != end)
		{
			std::cout << "[" << (*pos)[0] << "]";
			++pos;
		}
		std::cout << std::endl;
	}

	//regex token iterator
	{
		char* str = "*Link*||+Mario+||Zelda!!!||Metroid";
		cregex reg = cregex::compile("\\w+",icase);
		cregex_token_iterator pos(str,str+strlen(str),reg);
		while(pos!=cregex_token_iterator())
		{
			std::cout << "[" << *pos << "]";
			++pos;
		}
		std::cout << std::endl;

		cregex split_reg = cregex::compile("\\|\\|");
		pos = cregex_token_iterator(str,str+strlen(str),split_reg,-1);
		while(pos!=cregex_token_iterator())
		{
			std::cout << "[" << *pos << "]";
			++pos;
		}
		std::cout << std::endl;
	}
	return 0;
}
