/*
剑指 Offer 06. 从尾到头打印链表
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。


示例 1：

输入：head = [1,3,2]
输出：[2,3,1]

限制：

0 <= 链表长度 <= 10000
*/

// 思路一：反转
// 从头到尾将链表打印到数组中，返回反转后的结果即可。
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head){
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// 复杂度分析
// 时间复杂度：O(n)，reverse() 的时间复杂度为O(n)，遍历了一遍数组，复杂度也为O(n)。
// 空间复杂度：O(n)，使用了额外的 res。

// 思路二：递归
// 假设 head.next 已经排好序，那么只需将 head 添加到末尾即可。

// 其中，head.next 部分可以使用递归来实现，递归的终止条件为 head 为空

class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        if (!head) return res;
        reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};
// 复杂度分析
// 时间复杂度：O(n)，递归 n 次，时间间复杂度为O(n)，递归函数中的操作时间复杂度为O(1)，总时间复杂度为 O(n)\times O(1)=O(n)×O(1)=O(n)。
// 空间复杂度：O(n)，递归将占用链表长度的栈空间。

// 思路三：堆栈
// 利用堆栈先进后出的特点，先依次将元素压入堆栈中，然后将所有元素从堆栈中弹出，即可实现反转。


class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        stack<int> st;
        while(head){// push
            st.push(head->val);
            head = head->next;
        }
        while(!st.empty()){ // pop
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
// 复杂度分析
// 时间复杂度：O(n)，push 的间复杂度为 O(n)，pop 的间复杂度为O(n)。
// 空间复杂度：O(n)，使用了额外的 res 和 堆栈。

class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {

        //方法4：改变链表结构
        ListNode *pre = nullptr;
        ListNode *next = head;
        ListNode *cur = head;
        while(cur){
            next = cur->next;//保存当前结点的下一个节点
            cur->next = pre;//当前结点指向前一个节点，反向改变指针
            pre = cur;//更新前一个节点
            cur = next;//更新当前结点
        }
        while(pre){//上一个while循环结束后，pre指向新的链表头
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
    }
};

#include <vector>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};
