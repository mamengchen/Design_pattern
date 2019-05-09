//#include <iostream>
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <map>
//#include <vector>
//using namespace std;
//
////�зֳ�log��
////			������������ʱ�䣬��������
////map<int, vector<string>>:���Ϻ�|����ʱ��|��������
//map<int, vector<string>> Cache;
//
//class BugManager {
//public:
//	virtual void getBug() = 0;
//};
//
//class RealBugModel {
//public:
//	void getBugs()
//	{
//		ifstream in(".\\�����б�.txt");
//		if (!in)
//		{
//			cerr << "�ļ��򿪴���" << endl;
//			system("pause");
//		}
//		string line;
//		int i = 0;
//		while (getline(in, line))
//		{
//			Cache[i] = getCache(line);
//			i++;
//		}
//		in.close();
//	}
//
//private:
//	vector<string> getCache(string words)
//	{
//		vector<string> results;
//		istringstream ss(words);
//		while (!ss.eof())
//		{
//			string word;
//			getline(ss, word, '|');
//			results.push_back(word);
//		}
//		return results;
//	}
//};
//
//class ProxyBugModel {
//public:
//	ProxyBugModel(): m_reaload(false)
//	{}
//
//	void getBugs()
//	{
//		if (m_reaload)
//		{
//			cout << "���Ǵ�Cache���õ���" << endl;
//			showBugs();
//		}
//		else
//		{
//			cout << "������ʵ������" << endl;
//			(new RealBugModel())->getBugs();
//			m_reaload = true;
//			showBugs();
//		}
//	}
//private:
//	void showBugs()
//	{
//		for (int i = 0; i < Cache.size(); i++)
//		{
//			cout << "��" << i << "����";
//			for (vector<string>::iterator iter = Cache[i].begin(); iter != Cache[i].end(); iter++)
//			{
//				cout << *iter << " ";
//			}
//			cout << endl;
//		}
//	}
//private:
//	bool m_reaload;
//};
//
//int main1()
//{
//	ProxyBugModel* p = new ProxyBugModel();
//	for (int i = 0; i < 5; i++)
//	{
//		cout << "��" << i << "������" << endl;
//		p->getBugs();
//	}
//
//	system("pause");
//	return 0;
//}