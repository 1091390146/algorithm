#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
面试题 02.03. 删除中间节点
实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。

 

示例：

输入：单向链表a->b->c->d->e->f中的节点c
结果：不返回任何数据，但该链表变为a->b->d->e->f


class Solution {
public:
    void deleteNode(ListNode* node) {
        //将容貌换成后面节点的样子（1.狸猫易容）
        node->val=node->next->val;
        
        //借助指针p将node->next指向的那块堆空间释放（为了保证代码的健壮性）
        ListNode *p=node->next;

        //取而代之(2.狸猫换太子)
        node->next=node->next->next;

        //防止内存泄漏（为了保证代码的健壮性）
        delete p;

    }
};

*/

