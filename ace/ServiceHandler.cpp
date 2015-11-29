/*************************************************************************
	> File Name: ServiceHanlder.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年11月28日 星期六 13时56分45秒
 ************************************************************************/

#include "ServiceHandler.h"

int ServerHandler::open(void *p)
{
	if(super::open(p) == -1)
	{
		return -1;
	}

	ACE_INET_Addr peer_addr;
	if(this->peer().get_remote_addr(peer_addr) == 0
			&& peer_addr.addr_to_string(peer_name,MAXHOSTNAMELEN) == 0)
	{
		ACE_DEBUG((LM_DEBUG,ACE_TEXT("Connection from %s\n"),peer_name));
	}

	return 0;
}

int ServerHandler::close(ACE_HANDLE)
{
	ACE_DEBUG((LM_DEBUG,ACE_TEXT("Connection closed\n")));
	super::close();
	this->peer().close();

	return 0;
}

int ServerHandler::handle_input(ACE_HANDLE)
{
	const int INPUT_SIZE = 4096;
	char buffer[INPUT_SIZE];
	memset(buffer,0,INPUT_SIZE);

	int recv_cnt = this->peer().recv(buffer,sizeof(buffer));

	if(recv_cnt <= 0)
	{
		ACE_DEBUG((LM_DEBUG,ACE_TEXT("Connection close from %s\n"),peer_name));
		return -1;
	}
	ACE_DEBUG((LM_DEBUG,ACE_TEXT("Receive %d bytes msg from %s: %s\n"),recv_cnt,peer_name,buffer));


	return 0;
}
