#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <string>
#include <stack>

using namespace std;
/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
*/

/*
解题思路
思路很简单，我们尝试按照 popped 中的顺序模拟一下出栈操作，如果符合则返回 true，否则返回 false。这里用到的贪心法则是如果栈顶元素等于 popped 序列中下一个要 pop 的值，则应立刻将该值 pop 出来。

我们使用一个栈 st 来模拟该操作。将 pushed 数组中的每个数依次入栈，同时判断这个数是不是 popped 数组中下一个要 pop 的值，如果是就把它 pop 出来。最后检查栈是否为空。
算法
初始化栈 stack，j = 0；
遍历 pushed 中的元素 x；
当 j < popped.size() 且栈顶元素等于 popped[j]：
弹出栈顶元素；
j += 1；
如果栈为空，返回 True，否则返回 False。

/*

复杂度分析
时间复杂度：O(N)。将所以元素一遍入栈，一遍出栈，需要 O(2N)。
空间复杂度：O(N)。使用了辅助栈 st。
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = popped.size();
        int j = 0;
        for (int i = 0; i < pushed.size(); ++i){
            st.push(pushed[i]);
            while(!st.empty() && j < n && st.top() == popped[j]){
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }
};



int main(){
   
   system("pause"); 
   return 0;
}
