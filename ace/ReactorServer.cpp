/*************************************************************************
	> File Name: ReactorServer.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年11月28日 星期六 14时05分19秒
 ************************************************************************/

#include <ace/Reactor.h>
#include <ace/Acceptor.h>
#include <ace/SOCK_Acceptor.h>
#include <signal.h>
#include <iostream>
#include "ServiceHandler.h"

ACE_Acceptor<ServerHandler, ACE_SOCK_ACCEPTOR> server;

void sig_int(int num)
{
	ACE_Reactor::instance()->end_reactor_event_loop();
	server.close();
	std::cout << "CTRL + c " << std::endl;
}

int main()
{
	const int PORT = 30036;
	ACE_INET_Addr port_to_accept(PORT);
	signal(SIGINT,sig_int);
	if(server.open(port_to_accept) == -1)
	{
		return -1;
	}

	ACE_Reactor::instance()->run_reactor_event_loop();

	while(!ACE_Reactor::instance()->reactor_event_loop_done())
		;

	return 0;
}
