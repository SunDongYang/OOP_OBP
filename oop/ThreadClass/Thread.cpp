#include "Thread.h"

#include<iostream>
#include<string>

using namespace std;

Thread::Thread() : autoDelete_(false)
{
	cout<<"Thread Is Created ..."<<endl;
}

Thread::~Thread()
{
	cout<<"Thread Is Deleted ..."<<endl;
}
void Thread::Start()//启动线程
{
	pthread_create(&threadId_,NULL,ThreadRoutine,this);//第一个参数线程ID，第二个参数线程属性，this肯定是一个指向派生类的指针，基类为抽象类，不能实例化
						//第三个参数是现成的入口函数，
}
void Thread::Join()
{
	pthread_join(threadId_,NULL);
}

void* Thread::ThreadRoutine(void* arg)//静态成员函数不能调用非静态成员函数，它没有this指针
{
	Thread* thread = static_cast<Thread*>(arg);//把派生类转化为基类指针，并且调用它
	thread->Run();
	if(thread->autoDelete_)
		delete thread;
	return NULL;
}
void Thread::SetAutoDelete(bool autoDelete)
{
	autoDelete_ = autoDelete;
}

