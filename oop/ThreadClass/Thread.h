#ifndef _THREAD_H_
#define _THREAD_H_

#include<pthread.h>
#include<boost/function.hpp>
class Thread
{
public:
	Thread();
	virtual ~Thread();	//析构函数
	
	void Start();		//启动函数
	void Join();		//主要调用了pthread_jion()函数 

	void SetAutoDelete(bool autoDelete);
private:
	static void * ThreadRoutine(void*arg);//加了静态，就没有this指针了
	virtual void Run() = 0;			//Run函数是普通的成员函数，隐含的第一个参数
	//是Thread*(this),Run函数不能作为线程的入口函数。
	pthread_t threadId_;//线程ID
	bool autoDelete_;   //是否自动销毁
};

#endif // _THREAD_H_

/*
 *Run 是普通的成员函数，隐含的第一个是 Thread*（this）
 调用的时候是thiscall约定
 * */
