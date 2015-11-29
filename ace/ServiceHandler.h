/*************************************************************************
	> File Name: ServiceHandler.h
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年11月28日 星期六 13时52分52秒
 ************************************************************************/

#include <ace/Svc_Handler.h>
#include <ace/SOCK_Stream.h>

class ServerHandler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH>
{
	typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH> super;

public:
	int open(void* =0);
	int close(ACE_HANDLE fd=NORMAL_CLOSE_OPERATION);
	virtual int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE);

private:
	ACE_TCHAR peer_name[MAXHOSTNAMELEN];
};
