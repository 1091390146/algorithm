#include <iostream>
#include <windows.h>
#include <algorithm>
#include <string>

using namespace std;
/*
剑指 Offer 58 - I. 翻转单词顺序
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"

示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return s;
        int len = 0;
        string ans = "";
        for(int m = s.size() - 1; m >= 0; m--){
            if(s[m] != ' ')
                len++;
            if(s[m] == ' ' && len != 0){
                ans += s.substr(m + 1, len) + " ";
                len = 0;
                continue;
            }
        }
        if(len != 0)
            ans += s.substr(0, len) + " ";
        if(ans.size() > 0)
            ans.erase(ans.size() - 1, 1);
        return ans;
    }
};

int main(){
   
   system("pause");
   return 0;
}
