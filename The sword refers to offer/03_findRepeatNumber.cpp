// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

// 示例 1：

// 输入：
// [2, 3, 1, 0, 2, 5, 3]
// 输出：2 或 3 

// 算法复杂度 O(n*log(n)),因为C++的sort是O(n*log(n)),后面的遍历时间可忽略
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //1.排序
        sort(nums.begin(), nums.end());
        //2.遍历找出
        for (int i = 0; i < nums.size() - 2; i++) {
            if(nums[i]==nums[i + 1])
            {
                return nums[i];
            }
        }
        return -1;
    }
};

// 解法2 采用set的特性

/*
set的带有一bai个键参数的insert版本函数返回pair类型对du象，该对象包含一个迭代器和一个bool值，迭代器指向拥有该键的元素，而bool值表明是否添加了元素。
这里的second即是返回的pair里的bool值
*/
class Solution2 {
public:
    int findRepeatNumber(vector<int>& nums) {
        //* 遍历放进Set中,利用集合的特性(唯一性)进行解决
        //* 如果放不进去,那么就说明该元素重复
        set<int> myset;
        for (size_t i = 0; i < nums.size(); i++) {
            if(!myset.insert(nums[i]).second)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

// 解法3 使用unordered_set 更快

class Solution3 {
public:
    int findRepeatNumber(vector<int>& nums) {
        //* 遍历放进Set中,利用集合的特性(唯一性)进行解决
        //* 如果放不进去,那么就说明该元素重复
        unordered_set<int> myset;
        for (size_t i = 0; i < nums.size(); i++) {
            if(!myset.insert(nums[i]).second)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums;
    int n, temp;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &temp);
        nums.push_back(temp);
    }
    Solution s;
    int res = s.findRepeatNumber(nums);
    printf("res = %d", res);
    getchar();
    getchar();
    return 0;
}
