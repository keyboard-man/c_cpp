/*************************************************************************
	> File Name: counted_ptr.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年11月30日 星期一 23时38分14秒
 ************************************************************************/

#include <iostream>
#include "counted_ptr.h"

template<class T> counted_ptr<T>::counted_ptr(T* real)
	:real_ptr_(real),count_(new unsigned int)
{
	*count_ = 1;
	memcpy(real_ptr_,0,sizeof(T));
}

template<class T> counted_ptr<T>::~counted_ptr()
{
	*count_--;

	if(*count_ == 0)
	{
		delete real_ptr_;
		real_ptr_ = NULL;
		delete count_;
		count_ = NULL;
	}
}

template<class T> counted_ptr<T>::counted_ptr(counted_ptr<T>& source_ptr)
	:real_ptr_(source_ptr.real_ptr_),count_(source_ptr.count_)
{
	if(source_ptr == *this)
		return ;

	*count_++;
}

template<class T> counted_ptr<T>& counted_ptr<T>::operator=(counted_ptr<T> source_ptr)
{
	if(source_ptr == *this)
		return *this;

	*count_--;
	if(count_ == 0)
	{
		delete real_ptr_;
		delete count_;
	}

	real_ptr_ = source_ptr.real_ptr_;
	count_ = source_ptr.count_;
	*count_++;

	return *this;
}

template<class T> T* counted_ptr<T>::get(void)
{
	return real_ptr_;
}

template<class T> T& counted_ptr<T>::operator*()
{
	return (*real_ptr_);
}

template<class T> T* counted_ptr<T>::operator->()
{
	return real_ptr_;
}

template<class T> int counted_ptr<T>::count()
{
	return *count_;
}

template<class T> bool counted_ptr<T>::operator==(counted_ptr<T>& source_ptr)
{
	if((real_ptr_ = source_ptr.real_ptr_) && (count_ == source_ptr.count_))
		return true;
	else
		return false;
}

int main()
{
	counted_ptr<int> ptr(new int);
	std::cout << "value:" << *(ptr.get()) << std::endl;
	std::cout << "value:" << *ptr << std::endl << "count:" << ptr.count() << std::endl;

	counted_ptr<int> sen(ptr);
	*sen = 1;
	std::cout << "value:" << *ptr << std::endl << "count:" << ptr.count() << std::endl;

	counted_ptr<int> thr(new int);
	thr = ptr;
	std::cout << "value:" << *ptr << std::endl << "count:" << ptr.count() << std::endl;

	return 0;
}
