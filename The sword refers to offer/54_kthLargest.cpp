#include <iostream>

using namespace std;
/*
剑指 Offer 54. 二叉搜索树的第k大节点
给定一棵二叉搜索树，请找出其中第k大的节点。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4

https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/solution/mian-shi-ti-54-er-cha-sou-suo-shu-de-di-k-da-jie-d/
*/

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int res,k;

    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root){
        if(root == NULL)
            return;
        dfs(root->right);
        if(k == 0)
            return;
        if(--k == 0)
            res = root->val;
        dfs(root->left);
    }
};

int main(){
   
   system("pause");
   return 0;
}
