/*************************************************************************
	> File Name: assert.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年02月24日 星期三 09时46分56秒
 ************************************************************************/

#include <boost/format.hpp>
#include <iostream>

namespace boost{
    void assertion_failed(char const * expr, char const * function,
            char const * file, long line)
    {
        boost::format fmt("Assertion failed!\n Expression:%s\nFunction:%s\nFile:%s\nLine:%ld\n\n");
        fmt % expr % function % file % line;
        std::cout << fmt;
    }
}

#define BOOST_ENABLE_ASSERT_HANDLER
#include <boost/assert.hpp>

double func(int x)
{
	BOOST_ASSERT(x != 0 && "divided by zero -- BOOST");
	return 1.0 / x;
}

int main()
{
	func(0);

	return 0;
}
