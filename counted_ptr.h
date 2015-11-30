/*************************************************************************
	> File Name: counted_ptr.h
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年11月30日 星期一 23时26分41秒
 ************************************************************************/

#ifndef COUNTED_PTR_H_
#define COUNTED_PTR_H_
#include <cstring>

template<class T> class counted_ptr
{
public:
	counted_ptr<T>(T* real);
	~counted_ptr();
	counted_ptr<T>(counted_ptr<T>& source_ptr);
	counted_ptr<T>& operator= (counted_ptr<T> source_ptr);
	T* get(void);
	T& operator*();
	T* operator->();
	int count();
	bool operator ==(counted_ptr<T>& source_ptr);

private:
	T* real_ptr_;
	unsigned int* count_;
};
#endif
