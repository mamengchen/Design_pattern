//#include <string>
//#include <iostream>
//#include <memory>
//using namespace std;
//
//class IHello {
//public:
//	IHello()
//	{}
//	
//	virtual ~IHello()
//	{}
//
//	virtual void Output( const string& str)
//	{}
//};
//
//
//class Hello :public IHello {
//public:
//	void Output(const string& str) override {
//		cout << str << endl;
//	}
//};
//
//class HelloProxy : public IHello {
//public:
//	HelloProxy(IHello *p) : m_ptr(p)
//	{}
//
//	~HelloProxy()
//	{
//		delete m_ptr;
//		m_ptr = nullptr;
//	}
//
//	virtual void Output(const string& str) final {
//		cout << "在真正的对象执行之前，进行拦截" << endl;
//		m_ptr->Output(str);
//		cout << "在真正的对象执行之后，进行拦截" << endl;
//	}
//private:
//	IHello* m_ptr;
//};
//
//int main() {
//	std::shared_ptr<IHello> pHello = std::make_shared<HelloProxy>(new Hello());
//	pHello->Output("AOP");
//	system("pause");
//	return 0;
//}