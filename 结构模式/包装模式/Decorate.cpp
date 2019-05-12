//#include <iostream>
//#include <sstream>
//#include <deque>
//using namespace std;
//
//template <class T>
//string MyConverToStr(T obj)
//{
//	stringstream ss;
//	ss << obj;
//	return ss.str();
//}
//
//class Beverage {
//public:
//	virtual string GetDescription() = 0;
//	virtual double cost() = 0;
//
//protected:
//	string m_Description;
//};
//
//class CondimentDecorate : public Beverage
//{
//public:
//	virtual string GetDescription() = 0;
//protected:
//	CondimentDecorate(){}
//};
//
//
////这是一个装饰类
//class Soy :public CondimentDecorate
//{
//public:
//	Soy(Beverage *p) : m_pBeverage(p){}
//	
//	string GetDescription()
//	{
//		return m_pBeverage->GetDescription() + ",加了酱油了";
//	}
//
//	double cost()
//	{
//		return 0.1 + m_pBeverage->cost();
//	}
//private:
//	//持有被装饰的对象
//	Beverage *m_pBeverage;
//};
//
//class Milk :public CondimentDecorate
//{
//public:
//	Milk(Beverage *p) : m_pBeverage(p) {}
//
//	string GetDescription()
//	{
//		return m_pBeverage->GetDescription() + ",加了牛奶了";
//	}
//
//	double cost()
//	{
//		return 5 + m_pBeverage->cost();
//	}
//private:
//	//持有被装饰的对象
//	Beverage *m_pBeverage;
//};
//
//class Lattee : public Beverage
//{
//public:
//	Lattee()
//	{
//		m_Description = "拿铁";
//	}
//
//	string GetDescription()
//	{
//		return m_Description;
//	}
//
//	double cost()
//	{
//		return 13;
//	}
//};
//
//class Expresso : public Beverage
//{
//public:
//	Expresso()
//	{
//		m_Description = "浓缩咖啡";
//	}
//
//	string GetDescription()
//	{
//		return m_Description;
//	}
//
//	double cost()
//	{
//		return 13;
//	}
//};
//
//class Mecha : public Beverage
//{
//public:
//	Mecha()
//	{
//		m_Description = "摩卡咖啡";
//	}
//
//	string GetDescription()
//	{
//		return m_Description;
//	}
//
//	double cost()
//	{
//		return 13;
//	}
//};
//
//int main()
//{
//	
//	Beverage* pBeverage = new Expresso();
//	cout << pBeverage->GetDescription() << "价格是 " << MyConverToStr(pBeverage->cost()) << endl;
//
//	pBeverage = new Mecha();
//	pBeverage = new Soy(pBeverage);
//	pBeverage = new Milk(pBeverage);
//	cout << pBeverage->GetDescription() << "价格是 " << MyConverToStr(pBeverage->cost()) << endl;
//	system("pause");
//	return 0;
//}