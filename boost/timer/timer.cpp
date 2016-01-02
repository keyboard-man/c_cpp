/*************************************************************************
	> File Name: timer.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月02日 星期六 15时39分12秒
 ************************************************************************/

#include <boost/timer.hpp>
#include <iostream>

int main()
{
	//declara timer and begin keep time
	boost::timer t;

	//max time scale
	std::cout << "max timespan:" << t.elapsed_max() /3600 << "h" << std::endl;
	//min time scale
	std::cout << "min timespan:" << t.elapsed_min() << "s" << std::endl;
	//time spend
	std::cout << "now time elapesd:" << t.elapsed() << "s" << std::endl;

	return 0;
}
