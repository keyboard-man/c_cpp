/*************************************************************************
	> File Name: static_assert.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年02月24日 星期三 15时36分06秒
 ************************************************************************/

#include <boost/static_assert.hpp>
#include <iostream>

template<typename T>
T my_min(T a, T b)
{
    BOOST_STATIC_ASSERT_MSG(sizeof(T) < sizeof(int),"only short or char");
    return a<b?a:b;
}

int main()
{
    std::cout << my_min((short)1,(short)2) << std::endl;

    //complie error
    //std::cout << my_min(1L,3L) << std::endl;

    return 0;
}
