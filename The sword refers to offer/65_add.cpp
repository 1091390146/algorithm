#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 65. 不用加减乘除做加法
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

示例:

输入: a = 1, b = 1
输出: 2

提示：

a, b 均可能是负数或 0
结果不会溢出 32 位整数
*/

/*
https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/mei-ri-suan-fa-day-66-jing-dian-mian-shi-ti-bu-yon/
*/

class Solution {
public:
    int add(int a, int b) {
        while (b) {
            int carry = (unsigned int)(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};

class Solution {
public:
    int add(int a, int b) {
        return b ? add(a^b, (unsigned int)(a&b)<<1) : a;
    }
};

int main(){
   
   system("pause");
   return 0;
}
