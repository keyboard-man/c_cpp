/*************************************************************************
	> File Name: string_algo.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月07日 星期四 21时02分14秒
 ************************************************************************/

#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/assign.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <deque>

int main()
{
	std::string str("readme.txt");

	if(boost::ends_with(str,"txt"))
	{
		std::cout << boost::to_upper_copy(str) + " UPPER" << std::endl;
		assert(boost::ends_with(str,"txt"));
	}

	boost::replace_first(str,"readme","followme");
	std::cout << str << std::endl;

	std::vector<char> v(str.begin(),str.end());
	std::vector<char> v2 = boost::to_upper_copy(
			boost::erase_first_copy(v,"txt"));
	for(auto ch : v2)
	{
		std::cout << ch;
	}
	std::cout << std::endl;

	{
		std::string str("I Don't Know.\n");
		std::cout << boost::to_upper_copy(str);
		std::cout << str;
		boost::to_lower(str);
		std::cout << str;
	}

	{
		std::string str("Power Bomb");
		assert(boost::iends_with(str,"bomb"));
		assert(!boost::ends_with(str,"bomb"));

		assert(boost::starts_with(str,"Pow"));

		assert(boost::contains(str,"er"));

		std::string str2 = boost::to_lower_copy(str);
		assert(boost::iequals(str,str2));

		std::string str3("power suit");
		assert(boost::ilexicographical_compare(str,str3));

		assert(boost::all(str2.substr(0,5),boost::is_lower()));
	}

	{
		std::string str1("Samus"), str2("samus");

		assert(!boost::is_equal()(str1,str2));
		assert(boost::is_less()(str1,str2));
	}

	{
		boost::format fmt("|%s|\n");
		std::string str = "   samus aran   ";
		std::cout << fmt % boost::trim_copy(str);
		std::cout << fmt % boost::trim_left_copy(str);
		boost::trim_right(str);
		std::cout << fmt % str;

		std::string str2 = "2016 Happy new Year!!!";
		std::cout << fmt % boost::trim_left_copy_if(str2,boost::is_digit());
		std::cout << fmt % boost::trim_right_copy_if(str2,boost::is_punct());
		std::cout << fmt % boost::trim_copy_if(str2,
				boost::is_punct() || boost::is_digit() || boost::is_space());
	}

	{
		boost::format fmt("|%s|. pos = %d\n");
		std::string str = "Long long ago, there was a king.";
		boost::iterator_range<std::string::iterator> rge;

		rge = boost::find_first(str,"long");
		std::cout << fmt % rge % (rge.begin() - str.begin());

		rge = boost::ifind_first(str,"long");
		std::cout << fmt % rge % (rge.begin() - str.begin());

		rge = boost::find_nth(str,"ng",2);
		std::cout << fmt % rge % (rge.begin() - str.begin());

		rge = boost::find_head(str,4);
		std::cout << fmt % rge % (rge.begin() - str.begin());

		rge = boost::find_tail(str,5);
		std::cout << fmt % rge % (rge.begin() - str.begin());

		rge = boost::find_first(str,"samus");
		assert(rge.empty() && !rge);
	}

	{
		std::string str = "Samus beat the monster.\n";

		std::cout << boost::replace_first_copy(str,"Samus","samus");

		boost::replace_last(str,"beat","kill");
		std::cout << str;

		boost::replace_tail(str,9,"ridley.\n");
		std::cout << str;

		std::cout << boost::ierase_all_copy(str,"samus");
		std::cout << boost::replace_nth_copy(str,"l",1,"L");
		std::cout << boost::erase_tail_copy(str,8);
	}
	std::cout << std::endl;

	{
		std::string str = "Samus,Link.Zelda::Mario-Luigi+zelda";

		std::deque<std::string> d;
		boost::ifind_all(d,str,"zELDA");
		assert(d.size() == 2);
		for(auto x:d)
		{
			std::cout << "["<< x << "] ";
		}
		std::cout << std::endl;

		std::list<boost::iterator_range<std::string::iterator> > l;
		boost::split(l,str,boost::is_any_of(",.:-+"));
		for(auto x:l)
		{
			std::cout << "[" << x << "] ";
		}
		std::cout << std::endl;

		l.clear();
		boost::split(l,str,boost::is_any_of(".:-"),boost::token_compress_on);
		for(auto x:l)
		{
			std::cout << "[" << x << "]";
		}
		std::cout << std::endl;
	}

	{
		std::vector<std::string> v = boost::assign::list_of("Samus")("Link")("Zelda")("Mario");
		std::cout << boost::join(v, "+") << std::endl;
	}

	return 0;
}
