#include "Thread.h"
#include<unistd.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class TestThread: public Thread
{
public:
	TestThread(int count):count_(count)
	{
		cout<<"TestThread ..."<<endl;
	}
	~TestThread()
	{
		cout<<"~TestThread ..."<<endl;
	}
private:
	void Run()
	{
		while(count_--)
		{
			cout<<"This is a test ..."<<endl;
			sleep(1);
		}
	}
	int count_;
};

int main()
{
	/*
	TestThread t(5);
	t.Start();	//虚函数是具有回调功能的
	t.Join();	//线程对象的生命周期与线程的生命周期是不一样的。
	*/
	TestThread* t2 = new TestThread(5);	//怎么让线程自动销毁？即线程执行完毕，线程对象自动销毁
	t2->SetAutoDelete(true);
	t2->Start();
	t2->Join();

	for(;;)
		pause();
	return 0;
}
