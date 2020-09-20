#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
面试题 02.04. 分割链表
编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。

示例:

输入: head = 3->5->8->5->10->2->1, x = 5
输出: 3->1->2->10->5->5->8

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        ListNode* p = head,* p1 = head1,* p2 = head2;
        while(p){
            if(p->val < x){
                p1->next = p;
                p1 = p1->next;
            }else{
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }
        p1->next = head2->next;
        p2->next = nullptr;
        return head1->next;
    }
};
//O(n)
//O(1)
*/

