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
////����һ��װ����
//class Soy :public CondimentDecorate
//{
//public:
//	Soy(Beverage *p) : m_pBeverage(p){}
//	
//	string GetDescription()
//	{
//		return m_pBeverage->GetDescription() + ",���˽�����";
//	}
//
//	double cost()
//	{
//		return 0.1 + m_pBeverage->cost();
//	}
//private:
//	//���б�װ�εĶ���
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
//		return m_pBeverage->GetDescription() + ",����ţ����";
//	}
//
//	double cost()
//	{
//		return 5 + m_pBeverage->cost();
//	}
//private:
//	//���б�װ�εĶ���
//	Beverage *m_pBeverage;
//};
//
//class Lattee : public Beverage
//{
//public:
//	Lattee()
//	{
//		m_Description = "����";
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
//		m_Description = "Ũ������";
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
//		m_Description = "Ħ������";
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
//	cout << pBeverage->GetDescription() << "�۸��� " << MyConverToStr(pBeverage->cost()) << endl;
//
//	pBeverage = new Mecha();
//	pBeverage = new Soy(pBeverage);
//	pBeverage = new Milk(pBeverage);
//	cout << pBeverage->GetDescription() << "�۸��� " << MyConverToStr(pBeverage->cost()) << endl;
//	system("pause");
//	return 0;
//}