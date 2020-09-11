#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 61. 扑克牌中的顺子
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

示例 1:

输入: [1,2,3,4,5]
输出: True

示例 2:

输入: [0,0,1,2,5]
输出: True
 
限制：

数组长度为 5 

数组的数取值为 [0, 13] .
*/

/*
https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/solution/mian-shi-ti-61-bu-ke-pai-zhong-de-shun-zi-ji-he-se/
*/

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        bool flag[15];
        memset(flag, 0, sizeof(flag));
        int ma = 0, mi = 14;
        for(auto num : nums){
            if(num == 0)
                continue;
            if(flag[num])
                return false;
            flag[num] = true;
            ma = max(ma, num);
            mi = min(mi, num);
        }
        return ma - mi < 5;
    }
};

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int joker = 0;
        for(int i = 0; i < 4; i++){
            if(nums[i] == 0)
                joker++;
            else if(nums[i] == nums[i + 1]){
                return false;
            }
        }
        return nums[4] - nums[joker] < 5;
    }
};

int main(){
   
   system("pause");
   return 0;
}
