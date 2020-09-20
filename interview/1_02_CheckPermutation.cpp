/*
面试题 01.02. 判定是否互为字符重排
给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：

输入: s1 = "abc", s2 = "bca"
输出: true 
示例 2：

输入: s1 = "abc", s2 = "bad"
输出: false
*/
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> mp;
        for(auto c : s1){
            mp[c]++;
        }
        for(auto c : s2){
            mp[c]--;
        }
        for(int i = 0; i < 26; ++i){
            char c = i + 'a';
            if(mp[c] != 0)
                return false;
        }
        return true;
    }
};