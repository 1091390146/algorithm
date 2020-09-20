#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
/*
面试题 03.05. 栈排序
栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1。

示例1:

 输入：
["SortedStack", "push", "push", "peek", "pop", "peek"]
[[], [1], [2], [], [], []]
 输出：
[null,null,null,1,null,2]
示例2:

 输入： 
["SortedStack", "pop", "pop", "push", "pop", "isEmpty"]
[[], [], [], [1], [], []]
 输出：
[null,null,null,null,null,true]
*/

class SortedStack {
public:
    stack<int> s1, s2;
    SortedStack() {
        
    }
    
    void push(int val) {
        while(!s1.empty() && s1.top() < val){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    void pop() {
        if(!s1.empty())
            s1.pop();
    }
    
    int peek() {
        if(!s1.empty())
            return s1.top();
        return -1;
    }
    
    bool isEmpty() {
        return s1.empty();
    }
};

class SortedStack {
public:
    stack<int>s1;//原栈为降序
    stack<int>s2;//辅助栈为升序
    SortedStack() {

    }
    
    void push(int val) {
        while(!s2.empty() && s2.top() > val){//辅助栈中存在比val大的值
            s1.push(s2.top());
            s2.pop();
        }
        while(!s1.empty() && s1.top() < val){//原栈中有比val小的值
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
    }
    
    void pop() {
        while(!s2.empty()){//清空辅助栈
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty()) s1.pop();
    }
    
    int peek() {
        while(!s2.empty()){//清空辅助栈
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty()) return s1.top();
        else return -1;
    }
    
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};
