#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

/*
面试题 17.15. 最长单词
给定一组单词words，编写一个程序，找出其中的最长单词，且该单词由这组单词中的其他单词组合而成。若有多个长度相同的结果，返回其中字典序最小的一项，若没有符合要求的单词则返回空字符串。

示例：

输入： ["cat","banana","dog","nana","walk","walker","dogwalker"]
输出： "dogwalker"
解释： "dogwalker"可由"dog"和"walker"组成。
*/

/*
使用哈希集合存储列表中的每一个单词，接着遍历列表的中的每个单词判断其是否由其他单词组合而成
递归查找时，因为不能由其自身组成，因此每次从哈希集合中删除其自身
递归分割查找每一种可能，当一种分割到空串时，返回true，所有的情况遍历完毕，返回false

*/

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> allwords(words.begin(),words.end());//可通過interator來複製vector到unordered_set
        string ans;
        for(auto word:allwords){
            auto temp=allwords;//通過auto複製集合
            temp.erase(word);//erase()傳入元素可擦去集合中元素
            if(isCombinated(word,temp)){//查找word是否是其他元素組合
                if(word.size()>ans.size()) ans=word;
                if(word.size()==ans.size()) ans=min(word,ans);//Min傳入string,同樣長度情況下。min返回字典序小的那個string，實現返回通長度下字典序較小元素
            }
        }
        return ans;
    }
    bool isCombinated(string word,unordered_set<string>& words){
        if(word.size()==0) return true;//迭代終點
        for(int i=1;i<=word.size();i++){//substr記錄首位不記錄末尾終點，所以i取等號為迭代末尾
        if(words.count(word.substr(0,i))&&isCombinated(word.substr(i), words)) return true;//words.count()查看元素是否在集合内，如果不在返回0
        }
        return false;
    }
};