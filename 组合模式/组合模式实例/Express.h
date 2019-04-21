#pragma once
#include "ExpressNode.h"
#include <iostream>
using namespace std;
class Express {
public:
	Express(int);	//valueNode
	Express(char, const Express);  //unaryNode(char, int) Express('+',t,12)
	Express(char, const Express, const Express);  //����������������Express('+', 3, 4);
	Express(const Express&);
	Express& operator=(const Express&);
	friend ostream& operator<<(ostream& os, const Express& e)
	{
		os << *(e.p);
		return os;
	}
	~Express(void);
	int eval()const;
private:
	//����Ĺ����������ʵ�֣�����������˸��ָ����ı��ʽ
	class ExpressNode* p;
};