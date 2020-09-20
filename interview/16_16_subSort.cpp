#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 16.16. 部分排序
给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。

示例：

输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
输出： [3,9]
*/

/*
首先虽然题目没说，但是实际运行下来数列是单调递增的，所以我们下面默认数列是递增的。

那么对于元素 a[i] 来说，如果它左边存在大于 a[i] 的元素，那么 a[i] 是一定要参与到排序里去的。或者说如果它右边存在小于 a[i] 的元素，那么 a[i] 也是要参与到排序里去的。

所以我们只需要寻找最靠右的那个数（满足左边存在大于它的数），和最靠左的那个数（满足右边存在小于它的数），那么这两个数之间就是要排序的区间了。

为什么最靠右的那个（满足左边存在大于它的数）数一定能保证右边没有更小的数了呢？因为如果右边还有更小的数，那么那个更小的数才是更靠右的啊，这就矛盾了。

所以我们只需要从左到右扫描一遍，用一个变量维护一下最大值就行了，然后反向再遍历一遍，维护一个最小值。

链接：https://leetcode-cn.com/problems/sub-sort-lcci/solution/mei-ri-suan-fa-day-88-chao-yue-mei-mei-jiao-ni-zen/
*/

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        int n = array.size();
        int maxx = INT_MIN, minn = INT_MAX;
        int l = -1, r = -1;
        for (int i = 0; i < n; ++i) {
            if (array[i] < maxx) r = i;
            else maxx = array[i];
        }
        for (int i = n-1; i >= 0; --i) {
            if (array[i] > minn) l = i;
            else minn = array[i];
        }
        return {l, r};
    }
};
