//#include <iostream>
//using namespace std;
//class ThreePhaseoutlet {
//public:
//	void dothreePhasePlug()
//	{
//		cout << "�����ͷ����" << endl;
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
//		cout << "�������ڽ������ͷתΪ�����ͷ" << endl;
//	}
//};
//
////�������䣺�����Ը������һЩ
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
//		cout << "�������ڶ�һ�������ͷ�������ת��" << endl;
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