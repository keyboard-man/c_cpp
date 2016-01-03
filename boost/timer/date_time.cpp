/*************************************************************************
	> File Name: date_time.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月03日 星期日 12时23分53秒
 ************************************************************************/

#define BOOST_DATE_TIME_SOURCE
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

int main()
{
	boost::gregorian::date d1(2010,1,1);
	boost::gregorian::date d2 = boost::gregorian::from_string("2000-1-2");
	boost::gregorian::date d3 = boost::gregorian::from_string("2005/1/1");
	boost::gregorian::date d4 = boost::gregorian::from_undelimited_string("20010713");

	std::cout << "year:" << d1.year() << "\tmonth:" << d1.month() << "\tday:" << d1.day() << std::endl;
	std::cout << "day of week:" << d2.day_of_week() << std::endl;
	std::cout << "day of year:" << d3.day_of_year() << std::endl;
	std::cout << "week number:" << d4.week_number() << std::endl;

	std::cout << boost::gregorian::to_simple_string(d1) << std::endl;
	std::cout << boost::gregorian::to_iso_string(d2) << std::endl;
	std::cout << boost::gregorian::to_iso_extended_string(d3) << std::endl;
	std::cout << d4 << std::endl;

	std::cout << d1-d2 << std::endl;
	std::cout << (d2+=boost::gregorian::days(10)) << std::endl;
	std::cout << (d3+=boost::gregorian::months(2)) << std::endl;
	std::cout << (d4+=boost::gregorian::weeks(1)) << std::endl;

	return 0;
}
