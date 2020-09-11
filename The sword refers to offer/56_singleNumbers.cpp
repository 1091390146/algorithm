#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>

using namespace std;
/*
剑指 Offer 56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
*/

/*

*/

/*
https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-by-leetcode/
*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for(int n : nums){
            ret ^= n;
        }
        int div = 1;
        while((div & ret) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for(int n : nums){
            if(div & n)
                a ^= n;
            else
                b ^= n;
        }
        return vector<int> {a,b};
    }
};

int main(){
   
   system("pause");
   return 0;
}
