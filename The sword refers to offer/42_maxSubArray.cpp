#include <windows.h>
#include <vector>
#include <algorithm>


using namespace std;
/*
剑指 Offer 42. 连续子数组的最大和
输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/

/*
1.状态，即子问题。
dp[i] 代表以元素 nums[i] 为结尾的连续子数组最大和。

2.转移策略，自带剪枝。
若 dp[i−1]≤0 ，说明 dp[i−1] 对 dp[i] 产生负贡献，即 dp[i−1]+nums[i] 还不如 nums[i] 本身大。

3.状态转移方程，根据前两步抽象而来。

当 dp[i−1]>0 时：执行 dp[i] = dp[i-1] + nums[i]；
当 dp[i−1]≤0 时：执行 dp[i] = nums[i] ；
4.设计dp数组，保存子问题的解，避免重复计算

5.实现代码
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            nums[i] = max(nums[i - 1] + nums[i], nums[i]);
            res = max(nums[i], res);
        }
        return res;
    }
};
/*

*/


int main(){
   
   system("pause");
   return 0;
}
