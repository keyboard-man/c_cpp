/*************************************************************************
	> File Name: shared_ptr.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2016年01月05日 星期二 15时24分14秒
 ************************************************************************/

#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>
#include <iostream>
#include <string>
#include <vector>

class shared
{
private:
	boost::shared_ptr<int> p;
public:
	shared(boost::shared_ptr<int> p_):p(p_){
		
	}
	void print()
	{
		std::cout << "count: " << p.use_count()
			<< " v = " << *p << std::endl;
	}
};

void print_func(boost::shared_ptr<int> p)
{
	std::cout << "count: " << p.use_count()
		<< " v = " << *p << std::endl;
}

class sample
{
	private:
		class impl;
		boost::shared_ptr<impl> p;
	public:
		sample();
		void print();
};

class sample::impl
{
	public:
		void print()
		{
			std::cout << "impl print" << std::endl;
		}
};

sample::sample():p(new impl){

}

void sample::print()
{
	p->print();
}

int main()
{
	{
		boost::shared_ptr<int> sp(new int(10));
		assert(sp.unique());

		boost::shared_ptr<int> sp2 = sp;
		assert(sp == sp2 && sp.use_count() == 2);

		*sp2 = 100;
		assert(*sp == 100);

		sp.reset();
		assert(!sp);

		boost::shared_ptr<int> p(new int(100));
		shared s1(p), s2(p);

		s1.print();
		s2.print();

		*p = 20;
		print_func(p);
		s1.print();
	}

	{
		//factory function
		//template<class T,class... Args>
		//boost::shared_ptr<T> boost::make_shared(Args && ... args);
		boost::shared_ptr<std::string> sp = 
			boost::make_shared<std::string>("make_shared");
		boost::shared_ptr<std::vector<int> > spv =
			boost::make_shared<std::vector<int> >(10,2);
		assert(spv->size() == 10);
	}

	{
		typedef std::vector<boost::shared_ptr<int> > vs;
		vs v(10);

		int i = 0;
		for(vs::iterator pos=v.begin();pos!=v.end();++pos)
		{
			(*pos) = boost::make_shared<int>(++i);
			std::cout << *(*pos) << ", ";
		}
		std::cout << std::endl;

		boost::shared_ptr<int> p = v[9];
		*p = 100;
		std::cout << *v[9] << std::endl;

		for(auto& ptr : v)
		{
			ptr = boost::make_shared<int>(++i);
			std::cout << *ptr << ", ";
		}
		std::cout << std::endl;
	}

	{
		//bridge pattern

		sample s;
		s.print();
	}

	return 0;
}
