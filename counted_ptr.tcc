/*************************************************************************
	> File Name: counted_ptr.tcc
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年11月30日 星期一 23时38分14秒
 ************************************************************************/
#include <iostream>
#include "counted_ptr.h"

template<class T> 
counted_ptr<T>::counted_ptr(T* real)
	:real_ptr_(real),count_(new unsigned int)
{
	*count_ = 1;
	memset(real_ptr_,0,sizeof(T));
	std::cout << "value point to @" << real_ptr_ << ":" << *real_ptr_ << std::endl;
	std::cout << "count point to @" << count_ << ":" << *count_ << std::endl;
}

template<class T> 
counted_ptr<T>::~counted_ptr()
{
	(*count_)--;

	if(*count_ == 0)
	{
		std::cout << "free value point @" << real_ptr_ << std::endl;
		delete real_ptr_;
		real_ptr_ = NULL;
		std::cout << "free count point @" << count_ << std::endl;
		delete count_;
		count_ = NULL;
	}
}

template<class T> 
counted_ptr<T>::counted_ptr(const counted_ptr<T>& source_ptr)
	:real_ptr_(source_ptr.real_ptr_),count_(source_ptr.count_)
{
	(*count_)++;
	std::cout << "value point to @" << real_ptr_ << ":" << *real_ptr_ << std::endl;
	std::cout << "count point to @" << count_ << ":" << *count_ << std::endl;
}

template<class T> 
counted_ptr<T>& counted_ptr<T>::operator=(const counted_ptr<T>& source_ptr)
{
	if(source_ptr == *this)
		return *this;

	(*count_)--;
	if(*count_ == 0)
	{
		std::cout << "free value point @" << real_ptr_ << std::endl;
		delete this->real_ptr_;
		std::cout << "free count point @" << count_ << std::endl;
		delete this->count_;
	}

	real_ptr_ = source_ptr.real_ptr_;
	count_ = source_ptr.count_;
	(*count_)++;

	return *this;
}

template<class T> 
T* counted_ptr<T>::get(void) const
{
	return real_ptr_;
}

template<class T> 
T& counted_ptr<T>::operator*() const
{
	return (*real_ptr_);
}

template<class T> 
T* counted_ptr<T>::operator->() const
{
	return real_ptr_;
}

template<class T> 
int counted_ptr<T>::count() const
{
	return *count_;
}

template<class T> 
bool counted_ptr<T>::operator==(const counted_ptr<T>& source_ptr) const
{
	if((real_ptr_ == source_ptr.real_ptr_) && (count_ == source_ptr.count_))
		return true;
	else
		return false;
}

