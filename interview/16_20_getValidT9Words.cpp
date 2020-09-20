#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 16.20. T9键盘
在老式手机上，用户通过数字键盘输入，手机将提供与这些数字相匹配的单词列表。每个数字映射到0至4个字母。给定一个数字序列，实现一个算法来返回匹配单词的列表。你会得到一张含有有效单词的列表。映射如下图所示：



示例 1:

输入: num = "8733", words = ["tree", "used"]
输出: ["tree", "used"]
示例 2:

输入: num = "2", words = ["a", "b", "c", "d"]
输出: ["a", "b", "c"]
*/

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> ans;
        int n=num.size(),w=words.size();
        if(n==0||w==0) return ans;
        vector<char> table={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8',  '8','8','9','9','9','9'};//'t'-'a'
        for(string s:words){
            if(s.size()==n){
                int i=0;
                for(;i<n;i++){
                    if(table[int(s[i]-'a')]!=num[i]) break;
                }
                if(i==n) ans.push_back(s);
            }
        }
        return ans;
    }
};


