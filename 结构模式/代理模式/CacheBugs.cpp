//#include <iostream>
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <map>
//#include <vector>
//using namespace std;
//
////切分成log：
////			故障名，故障时间，故障描述
////map<int, vector<string>>:故障号|故障时间|故障描述
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
//		ifstream in(".\\故障列表.txt");
//		if (!in)
//		{
//			cerr << "文件打开错误" << endl;
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
//			cout << "这是从Cache中拿到的" << endl;
//			showBugs();
//		}
//		else
//		{
//			cout << "这是真实的数据" << endl;
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
//			cout << "第" << i << "行是";
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
//		cout << "第" << i << "次请求" << endl;
//		p->getBugs();
//	}
//
//	system("pause");
//	return 0;
//}