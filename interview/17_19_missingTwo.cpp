#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 17.19. 消失的两个数字
给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？

以任意顺序返回这两个数字均可。

示例 1:

输入: [1]
输出: [2,3]
示例 2:

输入: [2,3]
输出: [1,4]
*/

/*
求和：
找到缺失的一个数
->找到缺失的两个数

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        long sum = 0;
        for (auto x: nums) sum += x;

        int sumTwo = n * (n + 1) / 2 - sum, limits = sumTwo / 2;
        sum = 0;
        for (auto x: nums)
            if (x <= limits) sum += x; // 两个数不相同那么一个大于，一个小于
        int one = limits * (limits + 1) / 2 - sum;
        return {one, sumTwo - one};
    }
};

异或：
找到缺失的一个数
-> 找到缺失的两个数

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 1; i <= n + 2; i ++) ans ^= i;
        for (auto x: nums) ans ^= x;

        int one = 0;
        int diff = ans & -ans; 
        for (int i = 1; i <= n + 2; i ++)
            if (diff & i) one ^= i; // ?
        for (auto x: nums)
            if (diff & x) one ^= x;
        return {one, one ^ ans};
    }
};

原地hash
hash找到原来的位置
找到缺失的一个数
-> 找到缺失的两个数

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        for (int i = 0; i < 3; i ++) nums.push_back(-1);

        for (int i = 0; i < nums.size(); i ++)
            while (i != nums[i] && nums[i] != -1)
                swap(nums[i], nums[nums[i]]);
        
        vector<int> ans;
        for (int i = 1; i < nums.size(); i ++) 
            if (nums[i] == -1) ans.push_back(i);
        return ans; 
    }
};

*/

