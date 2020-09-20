#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
面试题 04.02. 最小高度树
给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。

示例:
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

          0 
         / \ 
       -3   9 
       /   / 
     -10  5 
*/


struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums, 0, nums.size() - 1);
    }

    TreeNode* help(vector<int>& nums, int low, int high){
        if(low > high) // low > high表示子数组为空
            return NULL;
        // 以mid作为根节点
        int mid = (high + low) >> 1; 
        TreeNode *root = new TreeNode(nums[mid]);
        // 左子数组[low, mid -1]构建左子树
        root->left = help(nums, low, mid - 1);
        // 右子数组[mid + 1, high]构建右子树
        root->right = help(nums, mid + 1, high);
        return root;
    }
};
