#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 08.07. 无重复字符串的排列组合
无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。

示例1:

 输入：S = "qwe"
 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
示例2:

 输入：S = "ab"
 输出：["ab", "ba"]
*/

class Solution {
public:
    vector<string> ans;
    vector<string> permutation(string S) {
        dfs(S, 0);
        return ans;
    }

    void dfs(string S, int idx) {
        int n = S.size();
        if (idx == n) ans.emplace_back(S);
        for (int i = idx; i != n; ++i) {
            string tmp = S;
            swap(tmp[idx], tmp[i]);
            dfs(tmp, idx + 1);
        }
    }
};

