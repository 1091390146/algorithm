#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 05.07. 配对交换
配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令（也就是说，位0与位1交换，位2与位3交换，以此类推）。

示例1:

 输入：num = 2（或者0b10）
 输出 1 (或者 0b01)
示例2:

 输入：num = 3
 输出：3
*/

/*
解题思路
如果一对一对地交换，必定有很多困难。

因此可以先操作奇数位，再操作偶数位。

对于奇数位，使用 101010（即 0xAA）作为掩码，提取奇数位，并把它们右移一位；
对于偶数位，使用 010101（即 0x55）作为掩码，提取偶数位，并把它们左移一位。
最后，将两次操作的结果合并成一个值。
*/

class Solution {
public:
    int exchangeBits(int num) {
        int even = (num & 0xaaaaaaaa) >> 1;
        int odd = (num & 0x55555555) << 1;
        return even | odd;
    }
};
