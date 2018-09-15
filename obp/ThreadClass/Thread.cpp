#include "Thread.h"
#include<iostream>

using namespace std;

Thread::Thread(const ThreadFunc& func) : func_(func),autoDelete_(false)
{
	cout<<"Thread Is Created ..."<<endl;
}

Thread::~Thread()
{
	cout<<"~Thread Is Deleted ..."<<endl;
}

void Thread::Start()
{
	pthread_create(&threadId_,NULL,ThreadRoutine,this);
}

void Thread::Join()
{
	pthread_join(threadId_,NULL);
}

void* Thread::ThreadRoutine(void* arg)
{
	Thread* thread = static_cast<Thread*>(arg);
	thread->Run();
	if(thread->autoDelete_)
		delete thread;
	cout<<"After Thread Deleted ..."<<endl;
	return NULL;
}
void Thread::SetAutoDelete(bool autoDelete)
{
	autoDelete_ = autoDelete;
}

void Thread::Run()	//不再是纯虚函数，可以自己实现
{
	func_();	//回调这个函数
}


