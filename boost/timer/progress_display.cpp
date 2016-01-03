/*************************************************************************
	> File Name: progress_display.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月03日 星期日 11时51分28秒
 ************************************************************************/

#include <boost/progress.hpp>
#include <fstream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> v(100);
	std::ofstream fs("./test.txt");

	boost::progress_display pd(v.size());

	for(auto &x : v)
	{
		fs << x << std::endl;
		++pd;
	}


	return 0;
}
