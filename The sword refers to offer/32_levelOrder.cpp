#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]
*/

/*
解题思路：
题目要求的二叉树的 从上至下 打印（即按层打印），又称为二叉树的 广度优先搜索（BFS）。
BFS 通常借助 队列 的先入先出特性来实现。

复杂度分析：
时间复杂度 O(N)： N为二叉树的节点数量，即 BFS 需循环 N次。
空间复杂度 O(N)： 最差情况下，即当树为平衡二叉树时，最多有 N/2个树节点同时在 queue 中，使用 O(N)大小的额外空间。
引申：析构vector的方法：
vector<int>().swap(num);
{ vector<int> tmp = curLevel; curLevel.swap(tmp);}

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int>ret;
        queue<TreeNode*> que;
        que.push(root);
        if(!root)return ret;
        TreeNode* temp;
        while(!que.empty()){
            temp=que.front();
            que.pop();
            ret.push_back(temp->val);
            if(temp->left)que.push(temp->left);
            if(temp->right)que.push(temp->right);
        }
        return ret;
    }
};
*/

/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

解题思路
两个思路，一个BFS，一个DFS，很经典的层序遍历题。

唯一注意的是要把每一层放到一起，需要维护一个level进行保存。

DFS记得使用引用&，不然就得维护一个全局变量了。

BFS的模板如下：


vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    //...
    while(q.size())
    {
        int size=q.size();
        //...
        for(int i=0;i<size;i++)
        {
            TreeNode* rt=q.front();q.pop();
            //...
            if(rt->left) q.push(rt->left);
            if(rt->right) q.push(rt->right);
        }
    }
    //return ...
}

代码
DFS：

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root,res,0);
        return res;
    }
    void dfs(TreeNode* root,vector<vector<int>>& res,int level)
    {
        if(!root) return;
        if(level>=res.size()) res.emplace_back(vector<int>());
        res[level].emplace_back(root->val);
        dfs(root->left,res,level+1);
        dfs(root->right,res,level+1);
    }
};

BFS:

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while(q.size())
        {
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                TreeNode* rt=q.front();q.pop();
                if(!rt) continue;
                level.push_back(rt->val);
                if(rt->left) q.push(rt->left);
                if(rt->right) q.push(rt->right);
            }
            if(level.size()!=NULL) res.push_back(level);
        }
        return res;
    }
};

*/

/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
思路：
奇偶层的打印顺序不一样是相反的，可以利用层数偶数与否调用reverse来解决，但是海量数据时这个效率很低，不推荐。

因为奇数层的打印顺序是从左到右，偶数层的打印顺序是从右到左，可以利用STL容器deque中

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        vector<vector<int>> res;
        bool flag = true; //从左向右打印为true，从右向左打印为false
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; ++i){
                if(flag){   // 前取后放：从左向右打印，所以从前边取，后边放入
                    TreeNode* rt = q.front();
                    q.pop_front();
                    if(!rt)
                        continue;
                    level.push_back(rt->val);
                    if(rt->left)
                        q.push_back(rt->left); // 下一层顺序存放至尾
                    if(rt->right)
                        q.push_back(rt->right);
                }else{  //后取前放： 从右向左，从后边取，前边放入
                    TreeNode* rt = q.back();
                    q.pop_back();
                    if(!rt)
                        continue;
                    level.push_back(rt->val);
                    if(rt->right)
                        q.push_front(rt->right);// 下一层逆序存放至首
                    if(rt->left)
                        q.push_front(rt->left);
                }
            }
            flag = !flag;
            if(!level.empty())
                res.push_back(level);
        }
        return res;
    }
};

*/


int main(){
   
   system("pause");
   return 0;
}
