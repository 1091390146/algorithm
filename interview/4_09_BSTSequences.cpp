#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
/*
面试题 04.09. 二叉搜索树序列
从左向右遍历一个数组，通过不断将其中的元素插入树中可以逐步地生成一棵二叉搜索树。给定一个由不同节点组成的二叉搜索树，输出所有可能生成此树的数组。

 

示例：
给定如下二叉树

        2
       / \
      1   3
返回：

[
   [2,1,3],
   [2,3,1]
]
*/

/*
首先，可以把二叉树看作一个拓扑图，一棵树的“根结点的数值”总是先于它的“左右子树中的结点的数值”被插入树中。
使用递归算法，依次枚举下一次插入的数值，变量buf用于构造数组。使用双端队列(变量q)存储这次可以插入的候选节点。

每次递归时，从双端队列q中取出候选值放入数组buf, 同时若候选值有左右子树，则将左右子树放进队列中。
若双端队列为q, 表示没有候选值，将buf放进结果ans中。
注意，每次选候选值结束时还原队列q与数组buf, 使其与输入时的值一致。

链接：https://leetcode-cn.com/problems/bst-sequences-lcci/solution/c-shi-yong-shuang-duan-dui-lie-di-gui-qiu-jie-16-m/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if (!root) return {{}};
        deque<TreeNode*> q;
        q.push_back(root);
        vector<int> buf;
        vector<vector<int> > ans;
        Inner(q, buf, ans);
        return ans;
    }
    void Inner(deque<TreeNode*> &q, vector<int> &buf, vector<vector<int> > &ans) {
        if (q.empty()) {
            ans.push_back(buf);
            return;
        }
        int size = q.size();
        while (size--) {
            TreeNode *r = q.front(); q.pop_front();
            buf.push_back(r->val);
            int children = 0;
            if (r->left) {
                ++children;
                q.push_back(r->left);
            }
            if (r->right) {
                ++children;
                q.push_back(r->right);
            }
            Inner(q, buf, ans);
            while (children--) {
                q.pop_back();
            }
            q.push_back(r);
            buf.pop_back();
        }
    }
};
