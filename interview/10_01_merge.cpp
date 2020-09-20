#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 10.01. 合并排序的数组
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

初始化 A 和 B 的元素数量分别为 m 和 n。

示例:

输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
*/

/*
方法 2: 双指针
复杂度分析
时间复杂度：O(m+n)
指针移动单调递增，最多移动m+n次，因此时间复杂度为O(m+n)。

空间复杂度：O(m+n)
需要建立长度为m+n的中间数组 sorted。

*/

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = 0, pb = 0;
        int sorted[m + n];
        int cur;
        while (pa < m || pb < n) {
            if (pa == m)
                cur = B[pb++];
            else if (pb == n)
                cur = A[pa++];
            else if (A[pa] < B[pb])
                cur = A[pa++];
            else
                cur = B[pb++];
            sorted[pa + pb - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i)
            A[i] = sorted[i];
    }
};

/*
方法3：逆向双指针

时间复杂度：O(m+n)
指针移动单调递减，最多移动m+n次，因此时间复杂度为O(m+n)。

空间复杂度：O(1)
直接对数组 A 原地修改，不需要额外空间。
*/
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = m - 1, pb = n - 1;
        int tail = m + n - 1;
        int cur;
        while (pa >= 0 || pb >= 0) {
            if (pa == -1)
                cur = B[pb--];
            else if (pb == -1)
                cur = A[pa--];
            else if (A[pa] > B[pb])
                cur = A[pa--];
            else
                cur = B[pb--];
            A[tail--] = cur;
        }
    }
};
