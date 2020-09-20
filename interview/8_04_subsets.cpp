#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 08.04. 幂集
幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

说明：解集不能包含重复的子集。

示例:

 输入： nums = [1,2,3]
 输出：
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/*
先在大容器里面存一个空容器[].
第一轮：n = 1
大容器：[] | [1];
第二轮：n = 2
大容器：[] [1] | [2] [1,2];
第三轮：n = 3
大容器：[] [1] [2] [1,2] | [3] [1,3] [2,3] [1,2,3] ;

作者：lao-wai-bo-zi-shu-7
链接：https://leetcode-cn.com/problems/power-set-lcci/solution/zhi-jie-sheng-cheng-fa-by-lao-wai-bo-zi-shu-7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
 vector<vector<int>> v;
    vector<vector<int>> subsets(vector<int>& nums) {
        v.push_back({});
        for(int i = 0 ; i < nums.size() ; i++){
             vector<vector<int>> b = v;
            for(int j = 0 ; j < b.size() ; j++){
                vector<int> a = v[j];
                a.push_back(nums[i]);
                v.push_back(a);
            }
        }
        return v;
    }
};
