#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 10.10. 数字流的秩
假设你正在读取一串整数。每隔一段时间，你希望能找出数字 x 的秩(小于或等于 x 的值的个数)。请实现数据结构和算法来支持这些操作，也就是说：

实现 track(int x) 方法，每读入一个数字都会调用该方法；

实现 getRankOfNumber(int x) 方法，返回小于或等于 x 的值的个数。

注意：本题相对原题稍作改动

示例:

输入:
["StreamRank", "getRankOfNumber", "track", "getRankOfNumber"]
[[], [1], [0], [0]]
输出:
[null,0,null,1]
*/

class StreamRank
{
    struct TreeNode
    {
        int sum;
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), sum(1), left(NULL), right(NULL) {}
    };

public:
    StreamRank()
    {
        root = NULL;
    }

    void track(int x)
    {
        if (!root)
        {
            root = new TreeNode(x);
            return;
        }

        TreeNode *cur = root;
        while (cur)
        {
            if (x <= cur->val)
            {
                cur->sum++;
                //相同的数字只增加其计数
                if (x == cur->val)
                    break;
                //如果左结点为空，则可以插入，结束搜索
                if (!cur->left)
                {
                    cur->left = new TreeNode(x);
                    break;
                }
                //否则计数向左搜索
                cur = cur->left;
            }
            else
            {
                if (!cur->right)
                {
                    cur->right = new TreeNode(x);
                    break;
                }
                //否则继续向右搜索
                cur = cur->right;
            }
        }
    }

    int getRankOfNumber(int x)
    {
        int ret = 0;
        if (root != NULL)
        {
            TreeNode *tmp = root;
            while (tmp && tmp->val != x)
            {
                if (x < tmp->val)
                    tmp = tmp->left;
                else //往右边查找的时候，加上父结点的计数
                {
                    ret += tmp->sum;
                    tmp = tmp->right;
                }
            }
            if (tmp != NULL)
                ret = ret + tmp->sum;
        }
        return ret;
    }

private:
    TreeNode *root;
};


/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */