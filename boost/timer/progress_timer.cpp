/*************************************************************************
	> File Name: progress_timer.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月02日 星期六 15时55分58秒
 ************************************************************************/

#include <iostream>
#include <boost/progress.hpp>

int main()
{
	{
		boost::progress_timer t;
		for(int i =0;i<1000;i++)
			;
	}

	{
		boost::progress_timer t;
		for(int i= 0;i<1000000000;i++)
			;
	}

	return 0;
}
