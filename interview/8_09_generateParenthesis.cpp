#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 08.09. 括号
括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。

说明：解集不能包含重复的子集。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        help(n, n, "");
        return ans;
    }

    void help(int l, int r, string a) {
        if (l == 0 && r == 0) {
            ans.emplace_back(a);
            return;
        }
        if (l != 0) help(l - 1, r, a + '(');
        if (l < r) help(l, r - 1, a + ')');
    }
};

