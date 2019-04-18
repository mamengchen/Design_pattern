#include <iostream>
#include <string>
#include <list>
using namespace std;

class Leaf {
public:
	Leaf(string name) :m_name(name)
	{}

	void showStruct(string preStr)
	{
		cout << preStr << "-" << m_name << endl;
	}
private:
	string m_name;
};


//文件夹
class Composite {
public:
	Composite(string name) :m_name(name)
	{}

	//加入组合对象
	void addComposite(Composite* pCom)
	{
		childComposite.push_back(pCom);
	}

	//加入叶子
	void addLeaf(Leaf* pLeaf)
	{
		childLeaf.push_back(pLeaf);
	}

	void showStruct(string preStr)
	{
		cout << preStr << "+" << m_name << endl;
		preStr += " ";
		for (list<Leaf*>::iterator iter = childLeaf.begin();
			iter != childLeaf.end(); iter++)
		{
			(*iter)->showStruct(preStr);
		}
		//输出当前对象
		for (list<Composite*>::iterator iter = childComposite.begin();
			iter != childComposite.end(); iter++)
		{
			(*iter)->showStruct(preStr);
		}
	}

private:
	string m_name;
	list<Leaf*> childLeaf;
	list<Composite*> childComposite;
};

int main()
{
	Composite* pRoot = new Composite("C:\\");
	Composite* pC1 = new Composite("mmc_files");
	Composite* pC2 = new Composite("linux");

	//定义文件结点
	Leaf *pLeaf1 = new Leaf("a.txt");
	Leaf *pLeaf2 = new Leaf("b.txt");

	Leaf *pLeaf3 = new Leaf("mmc.c");
	Leaf *pLeaf4 = new Leaf("sss.c");

	pRoot->addComposite(pC1);
	pRoot->addComposite(pC2);
	pC1->addLeaf(pLeaf1);
	pC1->addLeaf(pLeaf2);

	pC2->addLeaf(pLeaf3);
	pC2->addLeaf(pLeaf4);
	pRoot->showStruct("");
	system("pause");
	return 0;
}