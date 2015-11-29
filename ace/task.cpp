/*************************************************************************
	> File Name: ace_task.cpp
	> Author: He Jieting
    > mail: rambo@mail.ustc.edu.cn
	> Created Time: 2015年07月30日 星期四 09时10分31秒
 ************************************************************************/

#include <ace/Task.h>
#include <ace/Message_Block.h>
#include <ace/Message_Queue.h>
#include <ace/OS.h>
#include <iostream>
#include <string>

#define THR_NUM 1

using namespace std;

typedef struct Data
{
	int len;
	string str;
	int count;
}DataStruct;

class Consumer:public ACE_Task<ACE_MT_SYNCH>
{
public:
	Consumer(const string& str_to_show):
		show_str_(str_to_show)
	{

	}

	int open(void *)
	{
		cout << "This is Consumer open function" << endl;
		activate(THR_NEW_LWP,THR_NUM);
		return 0;
	}

	int svc(void)
	{
		cout << "This is Consumer svc function" << endl;
		while(true)
		{
			msg_ = 0;
			getq(msg_);
			if(msg_)
			{
				DataStruct *user = (DataStruct*)msg_->rd_ptr();
				cout << "DataStruct info:" << user->str << endl;
				delete user;
				msg_->release();
			}
		}

		return 0;
	}

	int close(u_long)
	{
		cout << "This is Consumer close function" << endl;

		flush();
		return 0;
	}

private:
	const string& show_str_;
	ACE_Message_Block * msg_;
};

class Producer : public ACE_Task<ACE_MT_SYNCH>
{
public:
	Producer(Consumer* consumer):consumer_(consumer)
	{

	}

	int open(void*)
	{
		cout << "This Producer open function" << endl;
		activate(THR_NEW_LWP,THR_NUM);

		return 0;
	}

	int svc(void)
	{
		cout << "This Producer svc function" << endl;

		DataStruct *user = new DataStruct();
		//strcpy(user->str,"hello");
		user->str = "hello";
		//user->len = strlen(user->str)+1;
		user->len = user->str.length();
		user->count = 1;
		msg_ = new ACE_Message_Block((char *)user,sizeof(*user));
		cout << sizeof(*user) << endl;
		consumer_->putq(msg_);
		cout << "done 1" << endl;

		ACE_OS::sleep(3);

		DataStruct *second = new DataStruct();
		second->str = "world";
		second->len = user->str.length();
		second->count = 1;
		msg_ = new ACE_Message_Block((char *)second,sizeof(*second));
		cout << sizeof(*second) << endl;
		consumer_->putq(msg_);
		cout << "done 2" << endl;


		return 0;
	}

	int close(u_long)
	{
		cout << "This Producer close function" << endl;

		return 0;
	}

private:
	Consumer* consumer_;
	ACE_Message_Block * msg_;
};

int main(int argc,char** argv)
{
	ACE::init();
	string str("This is the ACE_Task test program");
	Consumer* consumer = new Consumer(str);
	Producer* producer = new Producer(consumer);
	producer->open(0);
	consumer->open(0);

	ACE_OS::sleep(10);

	producer->close(0);
	consumer->close(0);

	//producer->open(0);
	//consumer->open(0);
	//ACE_OS::sleep(10);
	//producer->close(0);
	//consumer->close(0);
	ACE::fini();

	return 0;
}
