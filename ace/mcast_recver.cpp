/*************************************************************************
	> File Name: ace_recver.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年11月19日 星期四 09时51分30秒
 ************************************************************************/

#include <boost/thread.hpp>
#include <ace/INET_Addr.h>
#include <ace/SOCK_Dgram_Mcast.h>
#include <iostream>

int main()
{
	ACE_INET_Addr addr;
	ACE_INET_Addr remote_addr;
	ACE_SOCK_Dgram_Mcast mcast;
	int recv_size = 0;
	char buf[1024] = { };

	addr.set(30033,"239.0.0.1");
	mcast.join(addr);

	//while(true)
	for(int i=0;i<5;i++)
	{
		memset(buf,0,1024);
		recv_size = mcast.recv((void*)buf,1024,remote_addr,0);
		if(recv_size)
			std::cout << remote_addr.get_host_addr() << ":" << buf << std::endl;
	}

	mcast.leave(addr);
	mcast.close();
	addr.dump();
	addr.set(30033,"239.0.0.2");
	mcast.open(addr);
	mcast.join(addr);

	for(int i=0;i<5;i++)
	{
		memset(buf,0,1024);
		recv_size = mcast.recv((void*)buf,1024,remote_addr,0);
		if(recv_size)
			std::cout << remote_addr.get_host_addr() << ":" << buf << std::endl;
	}
	return 0;
}
