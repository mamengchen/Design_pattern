#include <iostream>
#include <deque>
#include <stack>
using namespace std;
//用STL默认的适配器，完成将一个deque转换成stack
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
	//可以从这里看出来deque与stack转化的deque有pop方法，而deque没有这个方法
	system("pause");
	return 0;
}