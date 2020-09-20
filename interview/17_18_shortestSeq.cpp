#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
面试题 17.18. 最短超串
假设你有两个数组，一个长一个短，短的元素均不相同。找到长数组中包含短数组所有的元素的最短子数组，其出现顺序无关紧要。

返回最短子数组的左端点和右端点，如有多个满足条件的子数组，返回左端点最小的一个。若不存在，返回空数组。

示例 1:

输入:
big = [7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7]
small = [1,5,9]
输出: [7,10]
示例 2:

输入:
big = [1,2,3]
small = [4]
输出: []
*/

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        vector<int> res;
        unordered_map<int, int> hashSmall;
        int count = 0, j = 0;
        for (auto e : small) {
            if (!hashSmall.count(e)) count++; // count的作用是记录small中元素的个数
            hashSmall[e]++;
        }
        for (int i = 0; i < big.size(); i++) {
            // 这一步的作用在于逐步扩大滑窗直至将所有的small元素包含进来
            hashSmall[big[i]]--;
            if (hashSmall[big[i]] == 0) count--;
            // count为0时进入循环
            while (!count) {
                // 由于上次处理后hashSmall中对应于big中非small部分hash的value = -1，因此，其加一后为0，循环直至找到第一个属于small的值，
                // 一次处理完成
                hashSmall[big[j]]++; // 这一步不仅用于分辨是否为small中元素，还用于找到下一个滑窗的进入位置。
                if (hashSmall[big[j]] > 0) {
                    count++;
                    if (res.empty() || res[1] - res[0] > i - j) res = {j, i};
                }
                j ++;
            }
        }
        return res;
    }
};


