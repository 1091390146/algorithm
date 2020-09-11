#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 57. 和为s的两个数字
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]
示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int sum, i = 0, j = nums.size() - 1;
        while(i < j){
            sum = nums[i] + nums[j];
            if(sum == target){
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                break;
            }else if(sum > target)
                j--;
            else
                i++;
        }
        return res;
    }
};

int main(){
   
   system("pause");
   return 0;
}
