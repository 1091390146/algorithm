#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
1. 两数之和
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

/*
https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-2/
*/

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> map;
        for(int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];
            if(map.find(complement) != map.end()){
                res.push_back(map[complement]);
                res.push_back(i);
                return res;
            }
            map[nums[i]] = i;
       }
        return res;
    }
};
*/


int main(){
   
   system("pause");
   return 0;
}
