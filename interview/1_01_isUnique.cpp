/*
面试题 01.01. 判定字符是否唯一
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

示例 1：

输入: s = "leetcode"
输出: false 
示例 2：

输入: s = "abc"
输出: true
*/
#include<string>
using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        int mark = 0;
        for(auto c : astr){
            if((mark & 1 << (c - 'a')) == 0)
                mark |= 1 << (c - 'a');
            else
                return false;
        }
        return true;
    }
};