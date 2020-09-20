#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
/*
面试题 05.04. 下一个数
下一个数。给定一个正整数，找出与其二进制表达式中1的个数相同且大小最接近的那两个数（一个略大，一个略小）。

示例1:

 输入：num = 2（或者0b10）
 输出：[4, 1] 或者（[0b100, 0b1]）
示例2:

 输入：num = 1
 输出：[2, -1]
提示:

num的范围在[1, 2147483647]之间；
如果找不到前一个或者后一个满足条件的正数，那么输出 -1。
*/

class Solution {
   public:
    vector<int> findClosedNumbers(int num) {
        bitset<32> small(num);
        bitset<32> bigger(num);//C++的 bitset 在 bitset 头文件中，它是一种类似数组的结构，它的每一个元素只能是０或１，每个元素仅用１bit空间。

        int s = -1;
        // small, 10 转 01，1移到左侧
        for (int i = 1; i < 32; i++) {
            if (small[i] == 1 && small[i - 1] == 0) {
                small.flip(i);
                small.flip(i - 1);
                for (int left = 0, right = i - 2; left < right;) {
                    while (left < right && small[left] == 0) left++;
                    while (left < right && small[right] == 1) right--;
                    small.flip(left);//flip()函数反置bitset中所有的位，即将1设为0，0设为1。如果指定pos，那么只有pos上的位被反置。
                    small.flip(right);
                }
                s = (int)small.to_ulong();
                break;
            }
        }

        // bigger, 01转10，1移到最右侧
        int b = -1;
        for (int i = 1; i < 32; i++) {
            if (bigger[i] == 0 && bigger[i - 1] == 1) {
                bigger.flip(i);
                bigger.flip(i - 1);

                for (int left = 0, right = i - 2; left < right;) {
                    while (left < right && bigger[left] == 1) left++;
                    while (left < right && bigger[right] == 0) right--;
                    bigger.flip(left);
                    bigger.flip(right);
                }
                b = (int)bigger.to_ulong();
                //控制bitset中的输出宽度的，输出与bitset<kuandu> ming(chushizhi)    
                //to_ulong()可以控制输出的最大限度，例如 kuandu是4，那么在输出时，每次结果都是 模除 2^4 - 1；如果宽度是5 那么结果都是 结果模除 2^5 - 1
                break;
            }
        }

        return {b, s};
    }
};