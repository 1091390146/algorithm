#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
面试题 05.06. 整数转换
整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B。

示例1:

 输入：A = 29 （或者0b11101）, B = 15（或者0b01111）
 输出：2
示例2:

 输入：A = 1，B = 2
 输出：2
*/

// 不断对 c 进行移位操作，然后检查最低有效位。

class Solution {
public:
    int convertInteger(int A, int B) {
        int res = 0;
        for (unsigned c = A ^ B; c != 0; c = c >> 1)
            res += c & 1; // 数一数 c 中有几个 1
        return res;
    }
};
// 方法三
// 不断翻转最低有效位，计算需要多少次 c 会变成 0。其中 ⚠️c = c & (c - 1) 是一个位操作的常用问题，可以特别注意一下。


class Solution {
public:
    int convertInteger(int A, int B) {
        int res = 0;
        for (unsigned c = A ^ B; c != 0; c = c & (c - 1))
            res ++;
        return res;
    }
};
// 复杂度分析
// 时间复杂度：O(1)。
// 空间复杂度：O(1)。

