#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <string>

using namespace std;
/*

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

 

示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
*/

/*
首尾双指针
定义头指针 left ，尾指针 right .
left 一直往右移，直到它指向的值为偶数
right 一直往左移， 直到它指向的值为奇数
交换 nums[left]和nums[right] .
重复上述操作，直到 left == right.
*/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if ((nums[left] & 1) != 0) {
                left ++;
                continue;
            }
            if ((nums[right] & 1) != 1) {
                right --;
                continue;
            }
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};


// 快慢双指针
// 定义快慢双指针 fast和 low，fast 在前， low在后 .
// fast的作用是向前搜索奇数位置，low的作用是指向下一个奇数应当存放的位置
// fast向前移动，当它搜索到奇数时，将它和 nums[low]交换，此时 low向前移动一个位置 .
// 重复上述操作，直到 fas指向数组末尾 .
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] & 1) {
                swap(nums[low], nums[fast]);
                low ++;
            }
            fast ++;
        }
        return nums;
    }
};


int main(){
    int n;
    scanf("%d", &n);
    vector<int> res(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &res[i]);
    }
    Solution s;
    s.exchange(res);
    for(auto num : res){
        printf("%d ", num);
    }
    system("pause");
    return 0;
}
