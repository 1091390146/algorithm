#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 50. 第一个只出现一次的字符
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "
*/

/*
class Solution {
public:
    char firstUniqChar(string s) {
        if(s == "")
            return ' ';
        //map中是对应字符出现的次数
        unordered_map<char,int> cmap;
        for(auto i = 0;i < s.size();i++)
        {
            cmap[s[i]]++;
        }
        //按字符串的顺序在map中查找到第一个出现一次的字符
        for(auto i = 0;i < s.size();i++)
        {
            if(cmap[s[i]] == 1)
                return s[i];
        }
        //没有找到
        return ' ';
    }
};

*/

/*

*/


int main(){
   
   system("pause");
   return 0;
}
