#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

/*
面试题 17.25. 单词矩阵
给定一份单词的清单，设计一个算法，创建由字母组成的面积最大的矩形，其中每一行组成一个单词(自左向右)，每一列也组成一个单词(自上而下)。不要求这些单词在清单里连续出现，但要求所有行等长，所有列等高。

如果有多个面积最大的矩形，输出任意一个均可。一个单词可以重复使用。

示例 1:

输入: ["this", "real", "hard", "trh", "hea", "iar", "sld"]
输出:
[
   "this",
   "real",
   "hard"
]
示例 2:

输入: ["aa"]q
输出: ["aa","aa"]
*/

/*
将所有单词插入Trie树
将单词按长度分组，哈希map
从单词长度最长组的开始遍历，对每组单词进行DFS搜索
利用Trie树检查是否合法，不合法回溯
有几处优化见注释，容易超时
*/

class trie
{
public:
	bool isEnd = false;
	trie* next[26] = {NULL};
	void insert(string& s)
	{
		trie *cur = this;
		for(int i = 0; i < s.size(); ++i)
		{
			if(!cur->next[s[i]-'a'])
				cur->next[s[i]-'a'] = new trie();
			cur = cur->next[s[i]-'a'];
		}
		cur->isEnd = true;
	}
};
class Solution {
	trie* t;
	vector<string> ans;
    vector<string> temp;
public:
    vector<string> maxRectangle(vector<string>& words) {
    	t = new trie();
    	map<int,vector<string>> m;
    	int maxlen = 0, maxarea = 0, area;
    	for(auto& w : words)
    	{
    		t->insert(w);//单词插入trie
    		m[w.size()].push_back(w);//单词按长度分组
    		maxlen = max(maxlen, int(w.size()));//最大单词长度
    	}
    	
    	for(auto it = m.rbegin(); it != m.rend(); ++it)
    	{	//反向遍历，从长度大的开始
    		if(maxarea/(it->first) >= maxlen)
    			break;//最长的单词*宽度 都不够大，这组不用找了
    		temp.clear();
    		area = 0;
    		dfs(it->second,maxarea,maxlen,area);
    	}
    	return ans;
    }

    void dfs(vector<string>& wd, int& maxarea, int maxlen, int area)
    {
        if(wd[0].size()*maxlen <= maxarea)//找到的面积到极限了，退出吧
            return;//这个优化必须有，没有会超时
        vector<bool> res;
    	for(int i = 0; i < wd.size(); ++i)
    	{
    		temp.push_back(wd[i]);
            res = isgood(temp);//是否合法
    		if(res[0])//可以往下加单词
    		{
                area = temp.size()*temp[0].size();
                if(res[1] && area > maxarea)//都是结束单词
    			{	//更新最大值
    				maxarea = area;
    				ans = temp;
    			}
    			dfs(wd, maxarea, maxlen, area);
    		}
    		// else//不能有else，有的话 if内的dfs出来，没有回溯
    		temp.pop_back();
    	}
    }

    vector<bool> isgood(vector<string>& tp)
	{
		trie *cur;
        bool allend = true;
		int i, j, n = tp[0].size();
		for(j = 0; j < n; ++j)//按列在trie中检查
		{
			cur = t;
			for(i = 0; i < tp.size(); ++i)
			{
				if(!cur->next[tp[i][j]-'a'])
					return {false, false};
				cur = cur->next[tp[i][j]-'a'];
			}
            allend &= cur->isEnd;
		}
		return {true, allend};//可以继续插入、每个列向单词都在字典中
	}
};
