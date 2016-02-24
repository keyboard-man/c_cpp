/*************************************************************************
	> File Name: test_fixture.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年02月24日 星期三 20时35分41秒
 ************************************************************************/

#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

#define BOOST_TEST_INCLUDE
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <iostream>
#include <vector>

using namespace boost;
struct global_fixture
{
    global_fixture()
    {
        std::cout << "global setup" << std::endl;
    }

    ~global_fixture()
    {
        std::cout << "global teardown" << std::endl;
    }
};

//BOOST_GLOBAL_FIXTURE(global_fixture)

struct assign_fixture
{
    assign_fixture()
    {
        std::cout << "suite setup" << std::endl;
    }

    ~assign_fixture()
    {
        std::cout << "suite teardown" << std::endl;
    }

    std::vector<int> v;
};

BOOST_FIXTURE_TEST_SUITE(s_assign,assign_fixture)

BOOST_AUTO_TEST_CASE(t_assign1)
{
    using namespace boost::assign;

    v += 1,2,3,4;
    BOOST_CHECK_EQUAL(v.size(),4);
    BOOST_CHECK_EQUAL(v[2],3);
}

BOOST_AUTO_TEST_CASE(t_assign2)
{
    using namespace boost::assign;

    push_back(v)(10)(20)(30);

    BOOST_CHECK_EQUAL(v.empty(),false);
    BOOST_CHECK_GT(v[0],v[1]);
}

BOOST_AUTO_TEST_SUITE_END()
