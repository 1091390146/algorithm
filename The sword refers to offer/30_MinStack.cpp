#include <windows.h>
#include <stack>

using namespace std;
/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.

*/

/*
用另一个栈记录min的变化值

class MinStack {
public:
    MinStack() {
    }
    stack<int>s;
    stack<int>Min;
    void push(int x) {
        s.push(x);
        if(Min.empty()||x<=Min.top())Min.push(x);
    }
    
    void pop() {
        if(!s.empty()){
            if(s.top()==Min.top())Min.pop();
            s.pop();
        }
    }
    int top() {
        return s.top();
    }
    int getMin() {
        return Min.top();
    }
};

*/
int main(){
   
   system("pause");
   return 0;
}
