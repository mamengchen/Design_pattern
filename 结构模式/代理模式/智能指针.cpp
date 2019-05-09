#include <iostream>
using namespace std;

template <class T>
class Auto_Ptr;

template <class T>
class Ref_Ptr {
	friend class Auto_Ptr<T>;

private:
	T* m_Ptr; //ʵ��ָ��
	size_t m_RefCount; //���ü���
	Ref_Ptr(T* p);
	virtual ~Ref_Ptr();
};

template <class T>
Ref_Ptr<T>::Ref_Ptr(T* p)
{
	m_Ptr = p;
	m_RefCount = 1;
	cout << "refptr���캯������" << endl;
}

template <class T>
Ref_Ptr<T>::~Ref_Ptr()
{
	if (m_Ptr)
	{
		cout << "refptr������������" << endl;
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
	cout << "auto_ptr���캯������" << endl;
}

template <class T>
Auto_Ptr<T>::Auto_Ptr(Auto_Ptr<T>& other)
{
	m_Pref = other.m_Pref;
	++(m_Pref->m_RefCount);
	cout << "auto_ptr�������칹�캯������" << endl;
}

template <class T>
Auto_Ptr<T>& Auto_Ptr<T>::operator=(Auto_Ptr& other)
{
	//���Ҳ�������Ӧ����+1
	++(other.m_Pref->m_RefCount);
	//�����������ָ�����¶������Խ�������-1
	//��ֹ�Ը�ֵ
	if (m_Pref)
	{
		if (--(m_Pref->m_RefCount) == 0)
		{
			delete m_Pref;
		}
	}
	m_Pref = other.m_Pref;
	printf("operator = ������,��ǰ�����ü�����%d\n", m_Pref->m_RefCount);
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
	cout << "auto_ptr���������ڵ���" << endl;
	if (--(m_Pref->m_RefCount) == 0)
	{
		cout << "ɾ��" << endl;
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