/*************************************************************************
	> File Name: scoped_ptr.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月04日 星期一 19时44分33秒
 ************************************************************************/

#include <boost/smart_ptr.hpp>
#include <iostream>

struct posix_file
{
	posix_file(const char * file_name)
	{
		std::cout << "open file:" << file_name << std::endl;
	}
	~posix_file()
	{
		std::cout << "close file" << std::endl;
	}
};

int main()
{
	boost::scoped_ptr<int> p(new int);
	if(p)
	{
		*p = 100;
		std::cout << *p << std::endl;
	}

	p.reset();
	assert(p == 0);
	if(!p)
	{
		std::cout << "scoped_ptr == null" << std::endl;
	}

	boost::scoped_ptr<posix_file> fp(new posix_file("/tmp/a.txt"));

	return 0;
}
