#include <stack>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 16.26. 计算器
给定一个包含正整数、加(+)、减(-)、乘(*)、除(/)的算数表达式(括号除外)，计算其结果。

表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

示例 1:

输入: "3+2*2"
输出: 7
示例 2:

输入: " 3/2 "
输出: 1
示例 3:

输入: " 3+5 / 2 "
输出: 5
*/

class Solution {
public:
    int calculate(string s) {
        char op = '+';
        int val;
        istringstream iss(s);
        stack<int> st;

        while(iss>>val){
            if(op=='+'){
                st.push(val);
            }else if(op=='-'){
                st.push(-val);
            }else{
                int val2 = st.top(); st.pop();
                if(op=='*') st.push(val*val2);
                else if(op=='/') st.push(val2/val);
            }
            iss>>op;
        }

        int res = 0;
        while(st.size()){
            res += st.top(); st.pop();
        }
        return res;
    }
};
