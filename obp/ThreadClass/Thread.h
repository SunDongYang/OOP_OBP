#ifndef _THREAD_H_
#define _THREAD_H_

#include<pthread.h>
#include<boost/function.hpp>


class Thread
{
public:
	typedef boost::function<void()> ThreadFunc;
	explicit Thread(const ThreadFunc& func); //explict让参数阻止隐式转换构造 ，让它只能显示调用
	~Thread();
	void Start();
	void Join();
	
	void SetAutoDelete(bool autoDelete);
private:
	static void * ThreadRoutine(void* arg);
	void Run();		//不设置虚函数
	ThreadFunc func_;	//Run方法调用func_函数
	pthread_t threadId_;
	bool autoDelete_;
};
#endif  // _THREAD_H_
