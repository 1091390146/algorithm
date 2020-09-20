#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
面试题 16.24. 数对和
设计一个算法，找出数组中两数之和为指定值的所有整数对。一个数只能属于一个数对。

示例 1:

输入: nums = [5,6,5], target = 11
输出: [[5,6]]
示例 2:

输入: nums = [5,6,5,6], target = 11
输出: [[5,6],[5,6]]
*/

//map
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (auto n : nums)
            mp[n]++;
        for (auto n : nums)
            if (--mp[n] >= 0 && --mp[target - n] >= 0)
            {
                ans.push_back({n, target - n});
                //mp[n]--, mp[target - n]--;
            }
        return ans;
    }
};

//双指针
vector<vector<int>> pairSums(vector<int>& nums, int target) {
    //取消同步特性，提高cin,cout效率
    vector<vector<int>> res;
    //排序
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum == target) {
            res.push_back({ nums[i],nums[j] });
            i++;
            j--;
        }
        else if (sum > target) j--;
        else i++;
    }
    return res;
}
