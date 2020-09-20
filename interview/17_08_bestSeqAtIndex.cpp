#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 17.08. 马戏团人塔
有个马戏团正在设计叠罗汉的表演节目，一个人要站在另一人的肩膀上。出于实际和美观的考虑，在上面的人要比下面的人矮一点且轻一点。已知马戏团每个人的身高和体重，请编写代码计算叠罗汉最多能叠几个人。

示例：

输入：height = [65,70,56,75,60,68] weight = [100,150,90,190,95,110]
输出：6
解释：从上往下数，叠罗汉最多能叠 6 层：(56,90), (60,95), (65,100), (68,110), (70,150), (75,190)
*/

/*
题目给出两个维度，两个维度上都满足严格递增的要求才可以叠上去。
考虑需要严格递增，先按照height 升序排序，同时height 相同的人按照tweight 降序排序。
这样排序下来，直接在数组中查找关于weight 的最长递增子序列就能得到答案。
一个升序，一个降序的是与我们的解决方法相关（我们在排序之后，直接查找体重的最长递增子序列就能得到答案），
如： height = [3, 2, 2, 3, 1, 6]，weight = [7,3,5,6,2,10]。两个都升序的排序结果是height=[1,2,2,3,3,6]，weight=[2,3,5,6,7,10]，直接查找体重的最长递增子序列结果是6，
可以看到，同一身高内部可能存在体重的递增。因此，会被加入结果。而使用身高升序，体重降序，排序结果为height=[1,2,2,3,3,6]，weight=[2,5,3,7,6,10]，可以看到体重的最长递增子序列结果是4。
*/
// 整个题目要求上面的人要比下面的人矮一点且轻一点，等价于下面的人要比上面的人矮一点且轻一点, 即反过来求
// 因为对于最优解路径, 正着求和反着求是同一个路径
// 为什么要反着求, 即从小到大, 那是因为对于std::lower_bound()这个二分函数, 要求从小到大才可以二分
// 先固定第一维度(即高度按从小到大的顺序排序, 高度相同则体重从大到小), 然后再对体重这维dp(这个其实也可以看做贪心)
// dp[i]表示前i个数, 体重递增顺序的前提下, 第i个元素的体重尽量小

class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int,int>> tmp;
        for(int i = 0; i < height.size(); i++) tmp.push_back({height[i], weight[i]});
        sort(tmp.begin(), tmp.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });
        vector<int> dp; //长度为N的地方 最小的数字
        for(const auto &[h, w]: tmp) {
            auto p = lower_bound(dp.begin(), dp.end(), w);  //二分查找第一个大于等于的地方
            if(p == dp.end()) dp.push_back(w);
            else *p = w;
        }
        return dp.size();
    }
};
