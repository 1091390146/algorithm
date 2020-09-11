#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>

using namespace std;
/*
剑指 Offer 51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:

输入: [7,5,6,4]
输出: 5

https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/shu-zu-zhong-de-ni-xu-dui-by-leetcode-solution/
*/
class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r){
        if(l >= r)
            return 0;
        int mid = (l + r) >> 1;
        int count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                tmp[pos] = nums[i];
                ++i;
            }else{
                tmp[pos] = nums[j];
                ++j;
                count += mid - i + 1;
            }
            ++pos;
        }
        for(int k = i; k <= mid; k++){
            tmp[pos++] = nums[k];
        }
        for(int k = j; k <= r; k++){
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};

int main(){
   
   system("pause");
   return 0;
}
