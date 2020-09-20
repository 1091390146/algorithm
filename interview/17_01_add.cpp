#include <algorithm>

using namespace std;

/*
设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。

示例:

输入: a = 1, b = 1
输出: 2
*/

class Solution {
public:
    int add(int a, int b) {
        while(b){ 
            auto carry = (unsigned int)(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
