#include <windows.h>

using namespace std;
/*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false
*/

/*
方法一： 递归法
找到递归点：左树与右树对称与否，与其跟两树的子树的对称情况有关系。

递归结束条件：

都为空指针则返回 true
只有一个为空则返回 false
两个指针当前节点值不相等 返回false
递归过程：

判断 A 的右子树与 B 的左子树是否对称
判断 A 的左子树与 B 的右子树是否对称

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool res = true;
        if (root!=NULL)
        {
            res = helper(root->left,root->right);
        }
        return res;
    }

    bool helper(TreeNode*A, TreeNode* B)
    {
        // 先写递归终止条件
        if (A==NULL && B==NULL)
            return true;
        // 如果其中之一为空，也不是对称的
        if (A==NULL || B==NULL)
            return false;
        // 走到这里二者一定不为空
        if (A->val != B->val)
            return false;
        // 前序遍历
        return helper(A->left,B->right) && helper(A->right,B->left);
    }
};
复杂度分析
时间复杂度O(n)，因为我们遍历整个输入树一次，所以总的运行时间为O(n)，其中n是树中结点的总数。
空间复杂度：递归调用的次数受树的高度限制。在最糟糕情况下，树是线性的，其高度为O(n)。因此，在最糟糕的情况下，由栈上的递归调用造成的空间复杂度为O(n)。

方法二： 迭代法
利用队列进行迭代。队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像。最初，队列中包含的是 root->left 以及 root->right。该算法的工作原理类似于 BFS，但存在一些关键差异。每次提取两个结点并比较它们的值。然后，将两个结点的左右子结点按相反的顺序插入队列中。当队列为空时，或者检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root ==NULL)
            return true;
        //用队列保存节点
        queue<TreeNode*> q;
        //将根节点的左右孩子放到队列中
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            //从队列中取出两个节点，再比较这两个节点
            TreeNode* A = q.front();
            q.pop();
            TreeNode* B = q.front();
            q.pop();
            //如果两个节点都为空就继续循环，两者有一个为空就返回false
            if (A==NULL && B==NULL)
                continue;
            if (A==NULL || B==NULL)
                return false;
            if (A->val != B->val)
                return false;
            //将左子树的左孩子， 右子树的右孩子放入队列
            q.push(A->left);
            q.push(B->right);
            //将左子树的右孩子，右子树的左孩子放入队列
            q.push(A->right);
            q.push(B->left);
        }
        return true;
    }
};
复杂度分析
时间复杂度：O(n)，因为我们遍历整个输入树一次，所以总的运行时间为O(n)，其中n是树中结点的总数。
空间复杂度：搜索队列需要额外的空间。在最糟糕情况下，我们不得不向队列中插入O(n)个结点。因此，空间复杂度为O(n)

*/

#include <queue>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return false;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* A = q.front();
            q.pop();
            TreeNode* B = q.front();
            q.pop();
            if(A == NULL && B == NULL)
                continue;
            if(A == NULL || B== NULL)
                return false;
            if(A->val != B->val)
                return false;
            q.push(A->left);
            q.push(B->right);
            q.push(A->right);
            q.push(B->left);
        }
    }
};

int main(){
   
   system("pause");
   return 0;
}
