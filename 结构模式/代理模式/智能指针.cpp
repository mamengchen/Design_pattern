#include <iostream>
using namespace std;

template <class T>
class Auto_Ptr;

template <class T>
class Ref_Ptr {
	friend class Auto_Ptr<T>;

private:
	T* m_Ptr; //实际指针
	size_t m_RefCount; //引用技术
	Ref_Ptr(T* p);
	virtual ~Ref_Ptr();
};

template <class T>
Ref_Ptr<T>::Ref_Ptr(T* p)
{
	m_Ptr = p;
	m_RefCount = 1;
	cout << "refptr构造函数调用" << endl;
}

template <class T>
Ref_Ptr<T>::~Ref_Ptr()
{
	if (m_Ptr)
	{
		cout << "refptr析构函数调用" << endl;
		delete m_Ptr;
		m_Ptr = nullptr;
		m_RefCount = 0;
	}
	
	m_Ptr = nullptr;
}

template <class T>
class Auto_Ptr {
public:
	Auto_Ptr();
	Auto_Ptr(T* p);
	~Auto_Ptr();

	Auto_Ptr<T> & operator = (Auto_Ptr& other);
	T& operator *();
	T* operator ->();

	Auto_Ptr(Auto_Ptr<T>& other);

private:
	Ref_Ptr<T>* m_Pref;
};

template <class T>
Auto_Ptr<T>::Auto_Ptr() {
	m_Pref = nullptr;
}

template <class T>
Auto_Ptr<T>::Auto_Ptr(T* p)
{
	m_Pref = new Ref_Ptr<T>(p);
	cout << "auto_ptr构造函数调用" << endl;
}

template <class T>
Auto_Ptr<T>::Auto_Ptr(Auto_Ptr<T>& other)
{
	m_Pref = other.m_Pref;
	++(m_Pref->m_RefCount);
	cout << "auto_ptr拷贝构造构造函数调用" << endl;
}

template <class T>
Auto_Ptr<T>& Auto_Ptr<T>::operator=(Auto_Ptr& other)
{
	//将右操作数对应引用+1
	++(other.m_Pref->m_RefCount);
	//由于左操作数指向了新对象，所以将操作数-1
	//防止自赋值
	if (m_Pref)
	{
		if (--(m_Pref->m_RefCount) == 0)
		{
			delete m_Pref;
		}
	}
	m_Pref = other.m_Pref;
	printf("operator = 被调用,当前的引用计数：%d\n", m_Pref->m_RefCount);
	return *this;
}

template <class T>
T& Auto_Ptr<T>::operator*()
{
	return *(m_Pref->m_Ptr);
}

template <class T>
T* Auto_Ptr<T>::operator->()
{
	return (m_Pref->m_Ptr);
}

template <class T>
Auto_Ptr<T>::~Auto_Ptr()
{
	cout << "auto_ptr析构函数在调用" << endl;
	if (--(m_Pref->m_RefCount) == 0)
	{
		cout << "删除" << endl;
		delete m_Pref;
		m_Pref = nullptr;
	}
}

int main()
{
	Auto_Ptr<int>* pPtr = nullptr;
	{
		Auto_Ptr<int> g_ptr;
		{
			Auto_Ptr<int> ptr1(new int(4));
			printf("%d\n", *ptr1);
			g_ptr = ptr1;
		}
		Auto_Ptr<int> ptr2(new int(3));
		g_ptr = ptr2;
		Auto_Ptr<int>* pPtr = &ptr2;
		printf("%d\n", *(*(pPtr)));
	}
	system("pause");
	return 0;
}