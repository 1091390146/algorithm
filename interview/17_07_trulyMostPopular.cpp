#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

/*
面试题 17.07. 婴儿名字
每年，政府都会公布一万个最常见的婴儿名字和它们出现的频率，也就是同名婴儿的数量。有些名字有多种拼法，例如，John 和 Jon 本质上是相同的名字，但被当成了两个名字公布出来。给定两个列表，一个是名字及对应的频率，另一个是本质相同的名字对。设计一个算法打印出每个真实名字的实际频率。注意，如果 John 和 Jon 是相同的，并且 Jon 和 Johnny 相同，则 John 与 Johnny 也相同，即它们有传递和对称性。

在结果列表中，选择字典序最小的名字作为真实名字。

示例：

输入：names = ["John(15)","Jon(12)","Chris(13)","Kris(4)","Christopher(19)"], synonyms = ["(Jon,John)","(John,Johnny)","(Chris,Kris)","(Chris,Christopher)"]
输出：["John(27)","Chris(36)"]
*/

/*
并查集，主要分为并操作和查操作
1、查操作，用来寻找祖先
2、并操作，能够将两个数据的祖先其中一个作为另一个的父节点，从而使得要合并的数据拥有同一个祖先

理解这两个操作就简单了，先初始化将每个数据的祖先设置为自己，接下来将要合并的数据进行并操作即可。最后只要找出祖先为自己的数据即可确定一共有哪些组。
*/

class Solution {
public:
	unordered_map<string, int> m_name_fre;//不需要排序应该用无序，比有序map效率提升不是一点半点
	unordered_map<string, string> m_parrent;
	string find(string name)//查操作，通过递归一直查到祖先，并且将路径上其他节点的父节点设置为祖先
	{
		if(m_parrent.count(name) == 0)
			return name;
		string root = find(m_parrent[name]);
		m_parrent[name]=root;
		return root;
	}
	void m_union(string n1, string n2)//并操作，将n1n2并为一类
	{
		n1 = find(n1);
		n2 = find(n2);
		if (n1 != n2)
		{
			//字典序比较
			if (n1 < n2)
				m_parrent[n2] = n1;
			else
				m_parrent[n1] = n2;
		}
	}
	vector<string> trulyMostPopular(const vector<string>& names, vector<string>& synonyms) {
		//对每个共同使用的名字对，进行并操作
		for (auto& name : synonyms)
		{
			int pos = name.find(',');
			string n1 = name.substr(1, pos - 1);
			string n2 = name.substr(pos + 1, name.size() - pos - 2);
			m_union(n1,n2);
		}
		//将每个被使用的名字和其频率加入map
		for (auto& name : names)
		{
			int pos = name.find('(');
			string nm = name.substr(0, pos);
			int ifre = stoi(name.substr(pos + 1, name.size() - pos - 2));
			m_name_fre[find(nm)] += ifre;
		}
		//保存结果
		vector<string> result;
		for (auto& name : m_name_fre)
		{
			string fre = to_string(name.second);
			result.push_back(name.first + "(" + fre + ")");
		}
		return result;
	}
};
