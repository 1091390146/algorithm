#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
面试题 04.05. 合法二叉搜索树
实现一个函数，检查一棵二叉树是否为二叉搜索树。

示例 1:
输入:
    2
   / \
  1   3
输出: true
示例 2:
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
*/


//二叉搜索树满足中序遍历为有序序列的性质，所以直接中序遍历判断是否有序即可。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> ans;
    void visit(TreeNode* root) {
        ans.push_back(root->val);
    }
    void dfs(TreeNode* root) {
        if (root != NULL) {
            dfs(root->left);
            visit(root);
            dfs(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        dfs(root);
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i + 1] <= ans[i])
                return false;
        }
        return true;
    }
};