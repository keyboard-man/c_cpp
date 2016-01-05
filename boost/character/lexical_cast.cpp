/*************************************************************************
	> File Name: lexical_cast.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月05日 星期二 20时54分02秒
 ************************************************************************/

#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>

//function to check character legitimacy
template<typename T>
bool num_vaild(const char* str)
try
{
	boost::lexical_cast<T>(str);
	return true;
}
catch(boost::bad_lexical_cast&) 
{
	return false;
};

int main()
{
	int x = boost::lexical_cast<int>("100");
	long y = boost::lexical_cast<long>("2000");
	float pai = boost::lexical_cast<float>("3.1415926e5");
	double e = boost::lexical_cast<double>("2.71828");

	std::cout << x << y << pai << e << std::endl;

	std::string str = boost::lexical_cast<std::string>(456);
	std::cout << str << std::endl;

	std::cout << boost::lexical_cast<std::string>(0.618) << std::endl;
	std::cout << boost::lexical_cast<std::string>(0x10) << std::endl;
	std::cout << boost::lexical_cast<bool>("1") << std::endl;

	try
	{
		std::cout << boost::lexical_cast<int>("0x100");
		std::cout << boost::lexical_cast<double>("HelloWorld");
		std::cout << boost::lexical_cast<long>("10000L");
		std::cout << boost::lexical_cast<bool>("false") << std::endl;
	}
	catch(boost::bad_lexical_cast& e)
	{
		std::cout << "error:" << e.what() << std::endl;
	}

	assert(num_vaild<double>("3.14"));
	assert(!num_vaild<int>("3.14"));
	assert(num_vaild<int>("65535"));

	return 0;
}
