#include <vector>
#include <algorithm>

using namespace std;

/*
面试题 10.11. 峰与谷
在一个整数数组中，“峰”是大于或等于相邻整数的元素，相应地，“谷”是小于或等于相邻整数的元素。例如，在数组{5, 8, 6, 2, 3, 4, 6}中，{8, 6}是峰， {5, 2}是谷。现在给定一个整数数组，将该数组按峰与谷的交替顺序排序。

示例:

输入: [5, 3, 1, 2, 3]
输出: [5, 1, 3, 2, 3]
*/

/*
假设按照峰-谷-峰的顺序排列数组，那么遍历一遍数组：
（1）如果i为峰的位置，则判断当前位置是否小于前一个位置（前一个为谷），若小于，则交换，大于则不处理。即： if(nums[i]<nums[i-1]) swap(nums[i],nums[i-1]);
（2）如果i为谷的位置，则判断当前位置是否大于前一个位置（前一个为峰），若大于，则交换，大于则不处理。即： if(nums[i]>nums[i-1]) swap(nums[i],nums[i-1]);

*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(i%2==0){
                if(nums[i]<nums[i-1]) swap(nums[i],nums[i-1]);
            }
            else{
                if(nums[i]>nums[i-1]) swap(nums[i],nums[i-1]);
            }
        }
    }
};
