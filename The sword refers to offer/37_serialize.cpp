#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;
/*
剑指 Offer 37. 序列化二叉树
请实现两个函数，分别用来序列化和反序列化二叉树。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
*/

/*
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp) {
                out<<tmp->val<<" ";
                q.push(tmp->left);
                q.push(tmp->right);
            } else {
                out<<"null ";
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        string val;
        vector<TreeNode*> vec;
        while (input >> val) {
            if (val == "null") {
                vec.push_back(NULL);
            } else {
                vec.push_back(new TreeNode(stoi(val)));
            }
        }
        int j = 1;                                          // i每往后移动一位，j移动两位，j始终是当前i的左子下标
        for (int i = 0; j < vec.size(); ++i) {              // 肯定是j先到达边界，所以这里判断j < vec.size()
            if (vec[i] == NULL) continue;                   // vec[i]为null时跳过。
            if (j < vec.size()) vec[i]->left = vec[j++];    // 当前j位置为i的左子树
            if (j < vec.size()) vec[i]->right = vec[j++];   // 当前j位置为i的右子树
        }
        return vec[0];
    }

};
*/

/*

*/


int main(){
   
   system("pause");
   return 0;
}
