#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
面试题 02.06. 回文链表
编写一个函数，检查输入的链表是否是回文的。

 

示例 1：

输入： 1->2
输出： false 
示例 2：

输入： 1->2->2->1
输出： true 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
//通过快慢指针找到中间结点
//通过头插法将链表前半段反转
//最后比较
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){//快慢指针找中间结点
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* p = head;
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        while(p->next != slow && p->next != NULL){//头插法反转前半段
            ListNode* r = p->next;
            p->next = r->next;
            r->next = dummyHead->next;
            dummyHead->next = r;
        }
        p = dummyHead->next;
        if(fast)//如果慢指针指向正中间的结点
            slow = slow->next;
        while(slow){//比较是否为回文
            if(slow->val != p->val)
                return false;
            slow = slow->next;
            p = p->next;
        }
        return true;
    }
};



