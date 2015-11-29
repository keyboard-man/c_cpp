/*************************************************************************
	> File Name: ace_sender.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年11月19日 星期四 09时44分15秒
 ************************************************************************/

#include <boost/thread.hpp>
#include <ace/INET_Addr.h>
#include <ace/SOCK_Dgram.h>
#include <ace/SOCK_Dgram_Mcast.h>
#include <iostream>

int main()
{
	ACE_INET_Addr addr;
	ACE_INET_Addr local_addr;
	ACE_SOCK_Dgram_Mcast mcast;
	char buf[1024] = { };

	addr.set(30033,"239.0.0.1");
	mcast.join(addr);
	for(int i=0;i<5;i++)
	{
		memset(buf,0,1024);
		buf[0] = i + '0';
		mcast.send((void*)buf,sizeof(i));
		std::cout << "send:" << i << std::endl;
		boost::this_thread::sleep_for(boost::chrono::seconds(1));
	}

	mcast.leave(addr);
	mcast.close();
	addr.dump();
	addr.set(30033,"239.0.0.2");
	mcast.open(addr);
	//mcast.join(addr);
	for(int i=0;i<5;i++)
	{
		memset(buf,0,1024);
		buf[0] = i + '0';
		mcast.send((void*)buf,sizeof(i));
		std::cout << "send:" << i << std::endl;
		boost::this_thread::sleep_for(boost::chrono::seconds(1));
	}

	return 0;
}
