#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <string>

using namespace std;
/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:

输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x),  next(NULL){}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL) return NULL;
        if(head->val == val) return head->next;
        ListNode *p = head;
        while(p->next){
            if(p->next->val == val){
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return head;
    }
};
// 时间复杂度O(n),空间O(1);

/*
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

int main(){

   system("pause");
   return 0;
}
