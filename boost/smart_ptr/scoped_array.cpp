/*************************************************************************
	> File Name: scoped_array.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月04日 星期一 20时08分21秒
 ************************************************************************/

#include <boost/smart_ptr.hpp>
#include <algorithm>

int main()
{
	int *arr = new int[100];
	boost::scoped_array<int> sa(arr);

	std::fill_n(&sa[0],100,5);
	sa[10] = sa[20] + sa[30];
	//*(sa + 1) = 20;    //error!
	
	return 0;
}
