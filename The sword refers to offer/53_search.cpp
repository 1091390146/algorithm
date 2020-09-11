#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 53 - I. 在排序数组中查找数字 I
统计一个数字在排序数组中出现的次数。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0

https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/solution/mian-shi-ti-53-i-zai-pai-xu-shu-zu-zhong-cha-zha-5/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //搜索有边界 right
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            int m = (i + j) >> 1;
            if(nums[m] <= target)
                i = m + 1;
            else
                j = m - 1;
        }
        int right = i;
        //若数组中无target 则提前返回
        if(j >= 0 && nums[j] != target)
            return 0;
        //搜索左边界 left
        i = 0, j = nums.size() - 1;
        while(i <= j){
            int m = (i + j) >> 1;
            if(nums[m] < target)
                i = m + 1;
            else
                j = m - 1;
        }
        int left = j;
        return right - left - 1;
    }
};

/*
剑指 Offer 53 - II. 0～n-1中缺失的数字
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

示例 1:

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            int m = (i + j) >> 1;
            if(nums[m] == m) 
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};

*/

int main(){
   
   system("pause");
   return 0;
}
