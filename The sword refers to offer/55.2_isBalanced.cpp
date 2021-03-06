#include <iostream>
#include <cmath>

using namespace std;
/*
剑指 Offer 55 - II. 平衡二叉树
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/solution/mian-shi-ti-55-ii-ping-heng-er-cha-shu-cong-di-zhi/
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }
    int recur(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = recur(root->left);
        if(left == -1)
            return -1;
        int right = recur(root->right);
        if(right == -1)
            return -1;
        return abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);

    }
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};

int main(){
   
   system("pause");
   return 0;
}
