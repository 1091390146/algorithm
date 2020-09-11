#include <windows.h>

using namespace std;
/*
剑指 Offer 35. 复杂链表的复制
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

示例 1：

输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

示例 2：
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

示例 3：
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]

示例 4：
输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
*/

/*
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

算法(迭代)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> mp;
        for (Node *it = head; it; it = it->next) {
            mp[it] = new Node(it->val);
        }
        for (Node *it = head; it; it = it->next) {
            if (it->next) mp[it]->next = mp[it->next];
            if (it->random) mp[it]->random = mp[it->random];
        }
        return mp[head];
    }
};

算法(dfs)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> used;
        return dfs(head, used);
    }
    
    Node* dfs(Node* head, unordered_map<Node*, Node*>& used) {
        if (!head) return nullptr;
        if (used.count(head)) return used[head];
        Node *res = new Node(head->val);
        used[head] = res;
        res->next = dfs(head->next, used);
        res->random = dfs(head->random, used);    
        return res;
    }
};
算法(bfs)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        return bfs(head);
    }
    
    Node* bfs(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> used;
        used[head] = new Node(head->val);
        queue<Node*> q;
        q.push(head);   
        while (!q.empty()) {
            int siz = q.size();
            for (int i = 0; i < siz; i++) {
                Node *t = q.front(); q.pop();
                if (t->next) {
                    if (!used[t->next]) {
                        used[t->next] = new Node(t->next->val);
                        q.push(t->next);
                    }
                    used[t]->next = used[t->next];
                }
                if (t->random) {
                    if (!used[t->random]) {
                        used[t->random] = new Node(t->random->val);
                        q.push(t->random);
                    }
                    used[t]->random = used[t->random];
                }
            }
        }
        return used[head];
    }
};

*/

int main(){
   
   system("pause");
   return 0;
}
