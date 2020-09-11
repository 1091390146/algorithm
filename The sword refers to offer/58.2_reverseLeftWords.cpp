#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 58 - II. 左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
*/

class Solution {
public:
    string reverse(string &s,int i,int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    
    string reverseLeftWords(string s, int n) {
        int size = (int)s.size();
        if (size <= 1) return s;
        reverse(s, 0, n-1);
        reverse(s, n, size-1);
        reverse(s, 0, size-1);
        return s;
    }
};

int main(){
   
   system("pause");
   return 0;
}
