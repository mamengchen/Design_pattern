#include <iostream>
#include <deque>
#include <stack>
using namespace std;
//��STLĬ�ϵ�����������ɽ�һ��dequeת����stack
int main1()
{
	deque<int> mydeq(3, 100);
	stack<int> myStack;
	stack<int> mystack2(mydeq);
	cout << "myStack Size" << (int)myStack.size() << endl;
	cout << "myStack2 size" << (int)mystack2.size() << endl;
	mystack2.pop();
	cout << "myStack2 size" << (int)mystack2.size() << endl;
	cout << "myStack2 top" << (int)mystack2.top() << endl;
	//���Դ����￴����deque��stackת����deque��pop��������dequeû���������
	system("pause");
	return 0;
}