/*************************************************************************
	> File Name: format.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月05日 星期二 21时15分36秒
 ************************************************************************/

#include <boost/format.hpp>
#include <iostream>
#include <iomanip>				//std::setfill std::setw

using boost::io::group;

int main()
{
	{
		std::cout << boost::format("%s:%d+%d=%d\n") % "sum" % 1 % 2 % (1+2);
		boost::format fmt("(%1% + %2%) * %2% = %3%\n");
		fmt % 2 % 5;
		fmt % ((2+5)*5);
		std::cout << fmt.str();
	}

	{
		boost::format fmt("%05d\n%-8.3f\n% 10s\n%05X\n");
		std::cout << fmt % 62 % 2.236 % "123456789" % 47;
	}


	{
		boost::format fmt("%1% %2% %3% %2% %1% \n");
		std::cout << fmt % 1 % 2 % 3;

		fmt.bind_arg(2,10);
		std::cout << fmt % 1 % 3;

		fmt.clear();

		std::cout << fmt % group(std::showbase,std::oct, 111) % 333;
		fmt.clear_binds();

		fmt.modify_item(1,group(std::hex,std::right,std::showbase,std::setw(8),std::setfill('*')));
		std::cout << fmt % 49 % 20 % 100;
	}
	return 0;
}
