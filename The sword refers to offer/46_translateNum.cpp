#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 46. 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
*/

/*
https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-by-leetcode-sol/
滚动数组法
class Solution {
public:
    int translateNum(int num) {
        string src = to_string(num);
        int p = 0, q = 0, r = 1;
        for (int i = 0; i < src.size(); ++i) {
            p = q; 
            q = r; 
            r = 0;
            r += q;
            if (i == 0) {
                continue;
            }
            auto pre = src.substr(i - 1, 2);
            if (pre <= "25" && pre >= "10") {
                r += p;
            }
        }
        return r;
    }
};

我的理解: 有点类似于青蛙跳阶梯，运用了滚动数组，比如 1 1 2 3 5；到了3的时候单独圈出3，
那 1 1 2 为一种， 看 2  3 那么 1 1 为一种 所以f(i - 1) + f(i - 2);
复杂度分析

记num=n。

时间复杂度：循环的次数是n的位数，故渐进时间复杂度为O(logn)。
空间复杂度：虽然这里用了滚动数组，动态规划部分的空间代价是O(1) 的，但是这里用了一个临时变量把数字转化成了字符串，故渐进空间复杂度也是O(logn)。
*/

/*
https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/cjian-ji-dai-ma-shuang-bai-by-orangeman/

递归
class Solution {
public:
    int translateNum(int num) {
        if (num < 10) return 1;
        return (num%100 < 10 || num%100 > 25) ? translateNum(num/10) : translateNum(num/10) + translateNum(num/100);
    }
};
*/


int main(){
   
   system("pause");
   return 0;
}
