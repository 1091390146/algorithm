#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
面试题 02.08. 环路检测
给定一个链表，如果它是有环链表，实现一个算法返回环路的开头节点。
有环链表的定义：在链表中某个节点的next元素指向在它前面出现过的节点，则表明该链表存在环路。
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)
        {
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
                break;
            }
        }
        if(fast!=slow)
        {
            return NULL;
        }
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};