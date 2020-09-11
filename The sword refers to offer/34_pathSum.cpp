#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/solution/tu-jie-hui-su-suan-fa-by-mrsate/
*/

/*
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return res;
        vector<int> nums;
        __pathSum(root, sum, nums);
        return res;
    }

    // nums: 根节点到当前节点路径的元素
    // want: target - sums(nums) = want
    void __pathSum(TreeNode* root, int want, vector<int>& nums){
        if(root == NULL)
            return;

        nums.push_back(root -> val); // 将本节点的 val 记录在 nums 中， 并向下传递
        if(want == root -> val && root -> left == NULL && root -> right == NULL){ //  root -> left == NULL && root -> right == NULL  是保证该节点为叶子节点
            res.push_back(nums); // sum(nums) == taget 则将 nums 放入全局的 res 中
        }

        __pathSum(root -> left, want - root -> val, nums);
        __pathSum(root -> right, want - root -> val, nums);

        nums.pop_back(); // 注意一定要进行 pop
    }
};

*/

int main(){
   
   system("pause");
   return 0;
}
