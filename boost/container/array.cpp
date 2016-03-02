/*************************************************************************
	> File Name: array.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年03月02日 星期三 13时42分01秒
 ************************************************************************/

#include <boost/array.hpp>
#include <iostream>

int main()
{
    boost::array<int, 10> ar;

    ar[0] = 1;
    ar.back() = 10;
    assert(ar[ar.max_size() -1] == 10);

    //make every one in ar is 777
    ar.assign(777);
    for(auto x:ar)
    {
        std::cout << x << ",";
    }
    std::cout << std::endl;

    //use pointer
    int *p = ar.c_array();
    *(p + 5) = 253;
    std::cout << ar[5] << std::endl;

    ar.at(8) = 666;
    std::sort(ar.begin(),ar.end());

    for(auto x:ar)
    {
        std::cout << x << ",";
    }
    std::cout << std::endl;

    return 0;
}
