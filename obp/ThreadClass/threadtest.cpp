#include"Thread.h"
#include<unistd.h>
#include<iostream>
#include<stdlib.h>
#include<boost/bind.hpp>

using namespace std;


class Foo
{
public:
	Foo(int count):count_(count){}

	void MemberFun1()
	{
		while(count_--)
		{
			cout<<"This Is A Test ..."<<endl;
			sleep(1);
		}
	}

	void MemberFun2(int x)
	{
		while(count_--)
		{
			cout<<"x= "<< x <<" This Is Another Test ..."<<endl;
			sleep(1);
		}
	}
	int count_;
};

void ThreadFunc1()
{
	cout<<"ThreadFunc ..."<<endl;
}

void ThreadFunc2(int count)
{
	while(count--)
	{
		cout<<"ThreadFunc2 ..."<<endl;
		sleep(1);
	}
}

int main(void)
{
	Thread t1(ThreadFunc1);
	Thread t2(boost::bind(ThreadFunc2,3));
	Foo foo1(3);
	Thread t3(boost::bind(&Foo::MemberFun1,&foo1));
	
	Foo foo2(3);
	Thread t4(boost::bind(&Foo::MemberFun2,&foo2,100));


	t1.Start();
	t2.Start();
	t3.Start();
	t4.Start();

	t1.Join();
	t2.Join();
	t3.Join();
	t4.Join();

	return 0;
}

