#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
面试题 17.10. 主要元素
数组中占比超过一半的元素称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回-1。

示例 1：

输入：[1,2,5,9,5,9,5,5,5]
输出：5
 

示例 2：

输入：[3,2]
输出：-1
 

示例 3：

输入：[2,2,1,1,1,2,2]
输出：2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       map<int,int>cut;
       int n = nums.size()/2;
       for(int i = 0;i < nums.size();i++)
       {
           cut[nums[i]]++;
           if(cut[nums[i]]>n)
                return nums[i];
       }         
       return -1;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, majority = 0;
        for(auto num : nums){
            if(!count)
                majority = num;
        
            if(num == majority)
                count++;
            else
                count--;
        }
        int C = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == majority) C++;
        }
        if(C <= nums.size() / 2) majority = -1;
        return majority;
    }
};
