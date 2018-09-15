#include<iostream>
#include<boost/function.hpp>
#include<boost/bind.hpp>
using namespace std;
class Foo
{
public:
	void memberFunc(double d,int i,int j)	//有一个隐含指针this，是第一个参数
	{
		cout<<d<<endl;//打印0.5
		cout<<i<<endl;//打印100
		cout<<j<<endl;//打印10
	}
};

//boost::bind 可以把一种函数接口适配成另一种函数接口，原函数可以是一个类的成员函数
//&取地址符号是不能省略的

int main()
{
	Foo foo;
	boost::function<void (int)> fp1 = boost::bind(&Foo::memberFunc,&foo,0.5,_1,1.0);
	//第三个参数_1是一个占位符
	//void(int) 可以看做是 void f(int)即一个返回为void的带有一个int参数的函数
	//这句话把后面的成员函数适配成前面的类型的一个接口
	fp1(100);//相当于调用 （&foo）->memberFunc(0.5,100,10)，100为占位符的值

	boost::function<void (int,int)> fp2 = boost::bind(&Foo::memberFunc,&foo,0.5,_1, _2);
	fp2(100,200);

	boost::function<void (int,int)> fp3 = boost::bind(&Foo::memberFunc,boost::ref(foo),0.5,_1, _2);		//&foo=>(&foo) ->memberFun(),boost::ref(foo)=>foo.memberFunc()
        fp3(10,20);

	return 0;
}

