/*************************************************************************
	> File Name: minimal.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年02月24日 星期三 16时14分42秒
 ************************************************************************/

#include <boost/test/minimal.hpp>
#include <boost/format.hpp>
#include <iostream>

int test_main(int argc, char* argv[])
{
    using namespace boost;
    format fmt("%d-%d");

    BOOST_CHECK(fmt.size() != 0);
    fmt % 12 % 34;
    BOOST_REQUIRE(fmt.str() == "12-34");

    BOOST_ERROR("test error message");

    fmt.clear();
    fmt % 12;
    try
    {
        std::cout << fmt;
    }
    catch(...)
    {
        BOOST_FAIL("PROGRAM FAIL, TEST FINISH");
    }

    return 0;
}
