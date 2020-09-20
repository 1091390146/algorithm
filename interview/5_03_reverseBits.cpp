#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
面试题 05.03. 翻转数位
给定一个32位整数 num，你可以将一个数位从0变为1。请编写一个程序，找出你能够获得的最长的一串1的长度。

示例 1：

输入: num = 1775(110111011112)
输出: 8
示例 2：

输入: num = 7(01112)
输出: 4
*/

class Solution {
public:
    int reverseBits(int nums) {
        // 优化: 节省空间复杂度
        int maxVal = 0;
        // 表示左侧连续 1 的个数
        int pre = 0;
        int i = 0;
        unsigned int num = (unsigned int)nums;//加上这句就通过了，日

        while(i < 32){
            if((num & 1) == 0){
                int sum = 0;
                num >>= 1;
                i ++;
                while(i < 32 && num != 0 && (num & 1) == 1){
                    num >>= 1;
                    i ++;
                    sum ++;
                }
                // 注意: 当前字符从 0 变 1 后也要统计在内
                maxVal = max(maxVal, sum + pre + 1);
                // 当前右侧连续为 1 的个数 也是 下一个 0 的左侧连续为 1 的个数
                pre = sum;
            }else{
                pre ++;
                num >>= 1;
                i ++;
            }
        }
        // 由于 2147483647 (0111 1111 1111 1111 1111 1111 1111 1111) 的存在, 所以必须跳出循环后再进行一次比较
        // 其次, 由于 -1 (1111 1111 1111 1111 1111 1111 1111 1111) 的存在, 所以必须保证值一定小于等于 32
        return max(maxVal, pre);
    }
};

/*
unsigned int a = -1;
unsigned int b = -2;
4294967295 4294967294
其中 2^32 - 1 = 4294967295
*/
