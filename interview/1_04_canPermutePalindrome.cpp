/*
面试题 01.04. 回文排列
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

回文串不一定是字典当中的单词。


示例1：

输入："tactcoa"
输出：true（排列有"tacocat"、"atcocta"，等等）
*/
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<int, int> mp;
        for(auto c : s)
            mp[c]++;
        int count = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second % 2 == 1)
                count++;
        }
        return count < 2;
    }
};