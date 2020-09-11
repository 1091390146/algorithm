#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 59 - I. 滑动窗口的最大值
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

/*
两步思路:
1、保证队列的头元素是最大值;
2、保证队列的头元素在滑动窗口内;
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for(int i = 0; i < nums.size(); ++i){
            while(!q.empty() && nums[i] > nums[q.back()])//每新增一个值就与前面的比较，比他小的统统丢掉，因为新增值肯定在滑动窗口内；
                q.pop_back();
            if(!q.empty() && q.front() + k < i + 1)//判断是否在滑动窗口内
                q.pop_front();
            q.push_back(i);
            if(i >= k - 1)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};

int main(){
   
   system("pause");
   return 0;
}
