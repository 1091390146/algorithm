#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 16.07. 最大数值
编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符。

示例：

输入： a = 1, b = 2
输出： 2
*/

/*
本质是平均值法： max(a, b) = ((a + b) + abs(a - b)) / 2。
*/

class Solution {
public:
    int maximum(int a, int b) {
        // double c = a;
        // double d = b;
        // int res = (int) ((Math.abs(c-d) + c + d)/2);
        // return res;

        long c = a;
        long d = b;
        int res = (int) ((fabs(c-d) + c + d)/2);
        return res;
    }
};

/*
绝对值的位运算
为了回避abs，利用位运算实现绝对值功能。
以int8_t为例：分析运算：(var ^ (var >> 7)) - (var >> 7)

var >= 0: var >> 7 => 0x00，即：(var ^ 0x00) - 0x00，异或结果为var

var < 0: var >> 7 => 0xFF，即：(var ^ 0xFF) - 0xFF，var ^ 0xFF是在对var的全部位取反，-0xFF <=> +1, 对signed int取反加一就是取其相反数。

举个栗子🌰：var = -3 <=> 0xFD，(var ^ 0xFF) - 0xFF= 0x02 - 0xff= 0x03
基于上述分析：

类型	    绝对值位运算
int8_t	    (var ^ (var >> 7)) - (var >> 7)
int16_t	    (var ^ (var >> 15)) - (var >> 15)
int32_t	    (var ^ (var >> 31)) - (var >> 31)
int64_t	    (var ^ (var >> 63)) - (var >> 63)

代码中(_diff ^ (_diff >> 63)) - (_diff >> 63)就是在求取long (int64_t)的绝对值。
*/
class Solution {
public:
    int maximum(int a, int b) {
        long _sum = long(a) + long(b);
        long _diff = long(a) - long(b);
        long _abs_diff = (_diff ^ (_diff >> 63)) - (_diff >> 63);
        return (_sum + _abs_diff) / 2;
    }
};
