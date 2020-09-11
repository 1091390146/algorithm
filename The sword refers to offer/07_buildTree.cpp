
#include <map>
#include <vector>
#include <iostream>

using namespace std;

// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

//  

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 限制：

// 0 <= 节点个数 <= 5000

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> Preorder ;
    map<int,int> dic;
    
    TreeNode* build(int pre_root, int in_left, int in_right){
        //如果左边界大于右边界说明到过了叶子
        if(in_left > in_right){
            return NULL;
        }
        //pre_root 是先序里面的索引 ！！
        TreeNode* root = new TreeNode(Preorder[pre_root]);
        //获取先序中的节点在中序中的节点， 即index 左边就是这节点的左子树，index右边就是节点的右子树
        int index = dic[Preorder[pre_root]];
        //当前节点左树即为先序索引+1 （没了话会在下一次迭代返回NULL）
        //我的理解，节点传入的是前序的节点，而left和right传入的位置则是中序，这是因为根据dic能够通过前序节点的位置找到中序节点的位置，
        //这样我们通过前序来储存节点，而通过中序来定义位置，进行判定；
        root->left = build(pre_root + 1, in_left, index - 1);
        //当前节点右树即为 根结点在前序中的索引+左树所有节点数（即节点在中序中的索引）-左边界+1 ，下一次的左边界为根在中序的索引+1  
        root->right = build(pre_root + index - in_left + 1, index + 1, in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //赋值至外部变量
        Preorder = preorder;
        //使用map映射inorder的值和索引，提高找到索引效率
        for(int i = 0; i < inorder.size(); i++){
            dic[inorder[i]] = i;
        }
        return build(0, 0, preorder.size() - 1);
    }
};
// 复杂度分析

// 时间复杂度：O(n)。对于每个节点都有创建过程以及根据左右子树重建过程。
// 空间复杂度：O(n)。存储整棵树的开销。

//后序+中序重构
//[9, 15, 7, 20 ,3]
//[9, 3, 15, 20, 7]
class Solution{
    vector<int> Postorder;
    map<int, int> mp;
public:

    TreeNode* build(int post_root, int left, int right){
        if(left > right)
            return NULL;
        TreeNode* root = new TreeNode(Postorder[post_root]);
        int index = mp[Postorder[post_root]];
        root->right = build(post_root - 1, index + 1, right);
        root->left = build(post_root - right + index - 1, left, index - 1);
    }

    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder){
        Postorder = postorder;
        for(int i = 0; i < inorder.size(); ++i){
            mp[inorder[i]] = i;
        }

    }
};