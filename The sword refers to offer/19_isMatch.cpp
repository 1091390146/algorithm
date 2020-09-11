#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
/*
请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
*/

/*
https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/zhu-xing-xiang-xi-jiang-jie-you-qian-ru-shen-by-je/
*/
class Solution{
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j){
                //分成空正则和非空正则两种
                if(j == 0)
                    f[i][j] = i == 0;
                else
                {
                    //非空正则分为两种情况 * 和 非*
                    if(p[j - 1] != '*'){
                        if(i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                            f[i][j] = f[i - 1][j - 1];
                    }
                    else
                    {   //碰到 * 了，分为看和不看两种情况
                        //不看
                        if(j >= 2)
                            f[i][j] = f[i][j - 2];//注意这里的f[j]对应的是字符串中第j个元素,从1开始,下面的p[j]中的是下标;
                        //看
                        if(i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                            f[i][j] = f[i - 1][j];
                        
                    }  
                }
                
            }
        }
        return f[n][m]; 
    }
};

/*
解题思路
特判，同时也是递归出口，如果p是空串，返回s是否为空串。如果p不为空，保证一定存在p[1]（可能是字符串结尾\0）
假如p[1] == * 的话，可以尝试两种情况：情况一是递归比较s和p.substr(2)；情况二是当s[0]可以匹配p[0]时, 尝试递归比较s.substr(1)和p，这里没有必要比较s.substr(1) 和 p.substr(2)，因为这种情况已经包含在递归比较s.substr(1)和p当中了
假如p[1] != *,如果p[0]不匹配s[0]，返回false，否则递归判断s.substr(1)和p.substr(1)
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p[1] == '*'){
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.')) && isMatch(s.substr(1), p);
        }
        else{
            return !s.empty() && (s[0] == p[0] || p[0] == '.') && (isMatch(s.substr(1), p.substr(1)));
        }
    }
};

int main(){
    string s, p;
    cin >> s;
    cin >> p;
    cout << s.size()<<" "<<p.size() << endl;
    // s.resize(100);
    // p.resize(100);
    // scanf("%s", &s[0]);
    // scanf("%s", &p[0]);
    Solution* s1 = new Solution();
    
    // printf("%d", s1->isMatch(s, p));
    cout << s1->isMatch(s, p);
    getchar();
    getchar();
    return 0;
}