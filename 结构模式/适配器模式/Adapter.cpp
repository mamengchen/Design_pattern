//#include <iostream>
//using namespace std;
//class ThreePhaseoutlet {
//public:
//	void dothreePhasePlug()
//	{
//		cout << "三相插头插入" << endl;
//	}
//
//};
//
//class TwoPhaseoutlet {
//public:
//	virtual void doPlug() = 0;
//};
//
//class OutletConverter : public TwoPhaseoutlet, public ThreePhaseoutlet {
//public:
//	void doPlug()
//	{
//		doConvertor();
//		dothreePhasePlug();
//	}
//
//	void doConvertor()
//	{
//		cout << "我们正在将三想插头转为两项插头" << endl;
//	}
//};
//
////对象适配：它可以更加灵活一些
//class OutletObjConvertor : public TwoPhaseoutlet {
//public:
//	OutletObjConvertor(ThreePhaseoutlet* pOut) : m_pOut(pOut)
//	{}
//
//	void doPlug()
//	{
//		doConvert();
//		m_pOut->dothreePhasePlug();
//	}
//
//	void doConvert()
//	{
//		cout << "我们正在对一个二相插头本身进行转化" << endl;
//	}
//private:
//	ThreePhaseoutlet* m_pOut;
//};
//
//int main(void)
//{
//	//TwoPhaseoutlet* pOutlet = new OutletConverter();
//	//pOutlet->doPlug();
//	
//	OutletObjConvertor* p = new OutletObjConvertor(new ThreePhaseoutlet);
//	p->doPlug();
//	system("pause");
//	return 0;
//}