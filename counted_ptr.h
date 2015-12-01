/*************************************************************************
	> File Name: counted_ptr.h
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年11月30日 星期一 23时26分41秒
 ************************************************************************/

#ifndef COUNTED_PTR_H_
#define COUNTED_PTR_H_
#include <cstring>

template<class T>
class counted_ptr
{
public:
	counted_ptr<T>(T* real);
	~counted_ptr();
	counted_ptr<T>(const counted_ptr<T>& source_ptr);
	counted_ptr<T>& operator= (const counted_ptr<T>& source_ptr);
	T* get(void) const;
	T& operator*() const;
	T* operator->() const;
	int count() const;
	bool operator ==(const counted_ptr<T>& source_ptr) const;

private:
	T* real_ptr_;
	unsigned int* count_;
};

#include "counted_ptr.tcc"

#endif
