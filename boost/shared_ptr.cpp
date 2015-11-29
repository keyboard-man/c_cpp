/*************************************************************************
	> File Name: shared_ptr.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年11月29日 星期日 15时55分00秒
 ************************************************************************/

#include <boost/smart_ptr.hpp>
#include <iostream>

int main()
{
	boost::shared_ptr<int> ptr(new int(6));
	std::cout << "the valuse ptr point to is : " << *ptr << std::endl;

	int i = 1;
	ptr.reset(&i);
	std::cout << "the valuse ptr point to is : " << *ptr << std::endl;

	//ptr.reset();		run error!! release stack memory
	return 0;
}
