#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 16.17. 连续数列
给定一个整数数组，找出总和最大的连续数列，并返回总和。

示例：

输入： [-2,1,-3,4,-1,2,1,-5,4]
输出： 6
解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/

/*

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            nums[i] = max(nums[i - 1] + nums[i], nums[i]);
            res = max(nums[i], res);
        }
        return res;
    }
};



// 分治法
int maxSubArray(vector<int>& nums)
{
    if(nums.size() == 0) return INT_MIN;
    return divide(nums,0,nums.size()-1);
}
int divide(vector<int>& nums, int left, int right)
{
    if(left == right) return nums[left];
    int mid = (left + right) / 2;
    // 1. 最大数列和在左边
    int sumLeft = divide(nums,left,mid);
    // 2. 最大数列和在右边
    int sumRight = divide(nums,mid+1,right);
    // 3. 最大数列和在中间
    // 先求左边的最大和
    int leftSum = 0,leftMaxSum = INT_MIN;
    for(int i = mid; i >= left; i--)
    {
        leftSum += nums[i];
        leftMaxSum = max(leftMaxSum,leftSum);
    }
    // 求右边的最大和
    int rightSum = 0,rightMaxSum = INT_MIN;
    for(int i = mid + 1; i <= right; i++)
    {
        rightSum += nums[i];
        rightMaxSum = max(rightMaxSum,rightSum);
    }
    return max(max(sumLeft,sumRight),leftMaxSum+rightMaxSum);
}
