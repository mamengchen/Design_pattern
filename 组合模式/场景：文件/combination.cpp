#include <iostream>
#include <string>
#include <list>
using namespace std;

//抽象文件
class IFile {
public:
	virtual void display() = 0;
	virtual int add(IFile* iFile) = 0;
	virtual int remove(IFile* iFile) = 0;
	virtual list<IFile*>* getChild() = 0;
};

class File :public IFile {
public:
	File(string name) :m_name(name)
	{}

	virtual void display()
	{
		cout << m_name << endl;
	}

	virtual int add(IFile* ifile)
	{
		return -1;
	}

	virtual int remove(IFile* ifile)
	{
		return -2;
	}

	virtual list<IFile*>* getChild()
	{
		return NULL;
	}
private:
	string m_name;
};

//目录：composite
class Dir :public IFile {
public:
	Dir(string name) :m_name(name) {
		m_list = new list<IFile*>;
	}

	virtual void display()
	{
		cout << m_name << endl;
	}

	virtual int add(IFile* ifile)
	{
		m_list->push_back(ifile);
		return 0;
	}

	virtual int remove(IFile* ifile)
	{
		m_list->remove(ifile);
		return 0;
	}

	virtual list<IFile*>* getChild()
	{
		return m_list;
	}
private:
	string m_name;
	list<IFile*>* m_list;
};

void showTree(IFile* root, int level)
{
	if (root == NULL)
		return;
	int i = 0;
	for (i = 0; i < level; i++)
	{
		printf("\t");
	}

	root->display();
	list<IFile*> *list1 = root->getChild();
	if (list1 != NULL)
	{
		for (list<IFile*>::iterator iter = list1->begin();
			iter != list1->end(); iter++)
		{
			if ((*iter)->getChild() == NULL)
			{
				for (i = 0; i < level; i++)
				{
					printf("\t");
				}
				(*iter)->display();
			}
			else {
				showTree(*iter, level + 1);
			}
		}
	}
}

int main(void)
{
	Dir* root = new Dir("C:");
	Dir* dir1 = new Dir("files");
	Dir* dir2 = new Dir("linux");

	File* file1 = new File("a.txt");
	File* file2 = new File("b.txt");
	File* file3 = new File("mmc.c");
	File* file4 = new File("sss.c");

	root->add(dir1);
	root->add(dir2);
	root->add(file1);
	dir1->add(file2);
	dir2->add(file3);
	dir2->add(file4);
	list<IFile*> *list1 = root->getChild();
	showTree(root, 0);

	system("pause");
	return 0;
}