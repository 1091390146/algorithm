#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*
https://leetcode-cn.com/problems/3sum/solution/san-shu-zhi-he-by-leetcode-solution/
*/

/*
class Solution {
public:

    vector<vector<int>> twoSum(vector<int>& nums, int start, int end, int target, int value){
        vector<vector<int>> ans;
        while(start < end){
            int sum = nums[start] + nums[end];
            if(sum == target){
                vector<int> res;
                res.push_back(value);
                res.push_back(nums[start]);
                res.push_back(nums[end]);
                ans.push_back(res);
                while(start < end && nums[start] == nums[start + 1])
                    start++;
                start++;
                while(start < end && nums[end] == nums[end - 1])
                    end--;
                end--;
            }else if(sum < target){
                start++;
            }else{
                end--;
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            auto res = twoSum(nums, i + 1, size - 1, -nums[i], nums[i]);
            ans.insert(ans.end(), res.begin(), res.end());
        }
        return ans;
    }
};
*/


int main(){
   
   system("pause");
   return 0;
}
