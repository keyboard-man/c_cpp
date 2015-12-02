/*************************************************************************
	> File Name: thread_detach.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年12月02日 星期三 10时14分21秒
 ************************************************************************/

#include <iostream>
#include <boost/thread.hpp>

void Print()
{
	static int i = 0;
	while(true)
	{
		std::cout << "No." << i++ << std::endl;
		boost::this_thread::sleep_for(boost::chrono::seconds(1));
	}
}

void lanch()
{
	boost::thread th(Print);

	//no diffient use or not use detach!
	//th.detach();
}

int main()
{
	lanch();
	std::cout << "lanch function returned, wait for 10 seconds" << std::endl;
	boost::this_thread::sleep_for(boost::chrono::seconds(10));

	return 0;
}
