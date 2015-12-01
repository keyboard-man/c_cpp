/*************************************************************************
	> File Name: counted_ptr_test.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年12月01日 星期二 10时50分54秒
 ************************************************************************/

#include <iostream>
#include "counted_ptr.h"

int main()
{
	counted_ptr<int> ptr(new int);
	std::cout << "value:" << *ptr << std::endl 
		<< "count:" << ptr.count() << std::endl << std::endl;

	counted_ptr<int> sen(ptr);
	*sen = 1;
	std::cout << "value:" << *ptr << std::endl 
		<< "count:" << ptr.count() << std::endl << std::endl;

	counted_ptr<int> thr(new int);
	thr = ptr;
	std::cout << "value:" << *ptr << std::endl 
		<< "count:" << ptr.count() << std::endl << std::endl;

	return 0;
}
