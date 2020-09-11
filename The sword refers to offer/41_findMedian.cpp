#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 41. 数据流中的中位数
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
*/

/*
方法一：排序法
此方法是最简单直接的一个方法，我们将添加的数保存在数组中，返回中位数时，只需将数组排序，返回中间位置数即可。

本题难度为 困难，显然一定存在更加优化的方法。

代码（C++ 超时）

class MedianFinder {
    vector<double> store;

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        store.push_back(num);
    }

    // Returns the median of current data stream
    double findMedian()
    {
        sort(store.begin(), store.end());

        int n = store.size();
        return (n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5);
    }
};
复杂度分析：
时间复杂度：O(nlogn)。addNum() 函数消耗(1)O(1) 的时间复杂度，findMedian() 函数使用了排序，时间复杂度为O(nlogn)。因此总的时间复杂度为(nlogn)=O(1)+O(nlogn)=O(nlogn)。
空间复杂度：O(n)。


*/

/*
方法二：二分查找插入
方法一的缺点在于对数组进行了排序操作，导致时间复杂度较高，假如每次插入一个值前数组已经排好序了呢？这样我们只需考虑每次将值插在合适的位置即可，所以使用二分查找来找到这个合适的位置，会将时间复杂度降低到O(n)（查找:O(logn)，插入: O(n)）。

代码

class MedianFinder {
    vector<int> store; // resize-able container

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int n = store.size();
        return n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};

复杂度分析
时间复杂度：O(n)。O(logn)+O(n)≈O(n)。
空间复杂度：O(n)。使用了数组保存输入。
*/

/*
方法三：优先队列（堆）

我们将中位数左边的数保存在大顶堆中，右边的数保存在小顶堆中。这样我们可以在O(1) 时间内得到中位数。
优先级队列: https://www.cnblogs.com/huashanqingzhu/p/11040390.html

class MedianFinder {
    priority_queue<int> lo;                              // 大顶堆
    priority_queue<int, vector<int>, greater<int>> hi;   // 小顶堆

public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num);                                    // 加到大顶堆

        hi.push(lo.top());                               // 平衡
        lo.pop();

        if (lo.size() < hi.size()) {                     // 维护两个堆元素个数
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};
复杂度分析
时间复杂度：O(logn)。堆插入和删除需要 O(logn)，查找中位数需要O(1)。
空间复杂度：O(n)。
*/


int main(){
   
   system("pause");
   return 0;
}
