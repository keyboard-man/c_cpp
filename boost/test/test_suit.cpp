/*************************************************************************
	> File Name: test_suit.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年02月24日 星期三 20时02分44秒
 ************************************************************************/

#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

#define BOOST_TEST_INCLUDE
#include <boost/test/unit_test.hpp>
#include <boost/smart_ptr.hpp>
using namespace boost;

BOOST_AUTO_TEST_SUITE(s_smart_ptr)

BOOST_AUTO_TEST_CASE(t_scoped_ptr)
{
    scoped_ptr<int> p(new int(874));
    BOOST_CHECK(p);
    BOOST_CHECK_EQUAL(*p,874);

    p.reset();
    BOOST_CHECK(p==0);
}

BOOST_AUTO_TEST_CASE(t_shared_ptr)
{
    shared_ptr<int> p(new int(123));
    BOOST_CHECK(p);
    BOOST_CHECK_EQUAL(*p,123);
    BOOST_CHECK_EQUAL(p.use_count(),1);

    shared_ptr<int> p2 = p;
    BOOST_CHECK_EQUAL(p2,p);
    BOOST_CHECK_EQUAL(p2.use_count(),2);

    *p2 = 255;
    BOOST_CHECK_EQUAL(*p,255);
    BOOST_CHECK_GT(*p,323);
}

BOOST_AUTO_TEST_SUITE_END()
