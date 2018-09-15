/*
 	Object-oriented programming and object-based programming
 	通过线程类的两种不同实现方法来理解面向对象编程风格和基于对象编程风格
 */
class EchoServer { 
public:
       	EchoServer() {
	       		server.SetConnectionCallback(boost::bind(onConnection)); 
			server.SecConnectionCallback(boost::bind(OnMessage)); 
			server.SecConnectionCallback(boost::bind(OnClose)); 
	}
       
	void OnConnection(){...} 
	void OnMessage(); 
	void OnClose();

	TcpServer server;
}

/*
 *	C编程风格，注册三个全局函数到网络库，网络库通过函数指针来回调
 *
 *	面向对象风格，用一个EchoServer继承TcpServer（抽象类）,实现三个接口OnConnection，OnMessage，OnClose
 * 
 *	基于对向风格，用一个EchoServer包含一个TcpServer（具体类）对象，在构造函数中用boost：：bind来注册三个成员函数
 *	OnConnection，OnMessage，OnClose
 * */
