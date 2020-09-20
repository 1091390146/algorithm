#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 17.21. 直方图的水量
给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的直方图，在这种情况下，可以接 6 个单位的水（蓝色部分表示水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

/*
对于每一列，找出当前列左边的最大值和右边的最大值，如果 curHeight < min(leftMax, rightMax)，则当前列水量为min(leftMax, rightMax) - curHeight，否则，当前不可能盛水。因此，首先需要构建左边和右边最大值的数组。实际上，左边最大值数组不需要提前构建，也不用数组，在求水量的过程中动态更新即可。
*/
class Solution {
   public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int n = height.size();

        vector<int> rightMax(height.size());
        rightMax[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);
        }

        int leftMax = 0;
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            leftMax = max(leftMax, height[i - 1]);
            int lowBound = min(leftMax, rightMax[i]);
            if (height[i] < lowBound) {
                res += (lowBound - height[i]);
            }
        }
        return res;
    }
};
