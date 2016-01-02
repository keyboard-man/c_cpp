/*************************************************************************
	> File Name: new_progress_timer.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月02日 星期六 16时42分59秒
 ************************************************************************/

#include <iostream>
#include <boost/progress.hpp>
#include <boost/static_assert.hpp>

template<int N = 2 >
class new_progress_timer:public boost::timer
{
public:
	new_progress_timer(std::ostream & os = std::cout)
		:m_os(os)
	{
		BOOST_STATIC_ASSERT(N >= 0 && N <= 10);
	}

	~new_progress_timer(void)
	{
		try
		{
			std::istream::fmtflags old_flags
				= m_os.setf(std::istream::fixed, std::istream::floatfield);
			std::streamsize old_prec = m_os.precision(N);

			m_os << elapsed() << " s\n" << std::endl;

			m_os.flags(old_flags);
			m_os.precision(old_prec);
		}
		catch(...)
		{

		}
	}

private:
	std::ostream & m_os;
};

template<>
class new_progress_timer<2>:public boost::progress_timer
{

};

int main()
{
	new_progress_timer<10> t;
	for(int i=0;i<1000000000;i++)
		;

	return 0;
}
