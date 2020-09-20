#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
面试题 01.05. 一次编辑
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

 

示例 1:

输入: 
first = "pale"
second = "ple"
输出: True
 

示例 2:

输入: 
first = "pales"
second = "pal"
输出: False
*/

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first == second)
            return true;
        int len1 = first.size();
        int len2 = second.size();
        if(abs(len1 - len2) > 1)
            return false;
        int i = 0, j = len1 - 1, k = len2 - 1;
        while(i < len1 && i < len2 && first[i] == second[i])
            i++;
        while(j >= 0 && k >= 0 && first[j] == second[k]){
            j--;
            k--;
        }
        return j - i < 1 && k - i < 1;
        //【1，插入或删除：其中短的字符串的下标相减为-1，长的字符串下标相减为0】
        //【2，替换，两字符串的下标相减均为0】
    }
};
