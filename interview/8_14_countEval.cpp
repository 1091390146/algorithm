#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 08.14. 布尔运算
给定一个布尔表达式和一个期望的布尔结果 result，布尔表达式由 0 (false)、1 (true)、& (AND)、 | (OR) 和 ^ (XOR) 符号组成。实现一个函数，算出有几种可使该表达式得出 result 值的括号方法。

示例 1:

输入: s = "1^0|0|1", result = 0

输出: 2
解释: 两种可能的括号方法是
1^(0|(0|1))
1^((0|0)|1)
示例 2:

输入: s = "0&0&0&1^1|0", result = 1

输出: 10
*/

/*
记：F[i][j][a=0/1]表示第i到j个数字计算结果为a的方案数。
转移：枚举区间分割点，讨论左右区间计算结果，方案数增量为左右方案数相乘。
时间复杂度：O(n^3) 空间复杂度：O(n^2)

思路：在某个运算符处进行分割，然后因为运算符左右两边只存在两种结果。 0 和 1
比如 "0&0&0	  &   1^1|0"	 
运算符 & 分割后，左边的结果最终只能是 1 或 0 其中一个
右边的结果最终只能是 1 或 0 其中一个
即最终是 0 和 0 、1 和 1、 0 和 1、 1 和 0 进行 &，那么我们只需要统计左右两边存在多少个 0 和 1
进行乘积即可
*/
class Solution {
public:
    int countEval(string s, int result) {
        int len=s.size();
        vector<int> A;
        vector<char> opt;
        for (int i=0;i<len;++i)
            if (i&1) opt.push_back(s[i]);
            else A.push_back(s[i]-'0');
        int n=A.size();
        int F[n][n][2];
        for (int i=0;i<n;++i) F[i][i][A[i]]=1,F[i][i][A[i]^1]=0;
        for (int l=2;l<=n;++l)
        {
            for (int i=0;i+l-1<n;++i)
            {
                int j=i+l-1;
                F[i][j][0]=F[i][j][1]=0;
                for (int k=i;k<j;++k)
                    if (opt[k]=='&')
                    {
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][1]*F[k+1][j][0];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][0];
                    }
                    else if (opt[k]=='|')
                    {
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][1];
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][0];
                        F[i][j][1]+=F[i][k][0]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][0];
                    }
                    else
                    {
                        F[i][j][0]+=F[i][k][1]*F[k+1][j][1];
                        F[i][j][1]+=F[i][k][1]*F[k+1][j][0];
                        F[i][j][1]+=F[i][k][0]*F[k+1][j][1];
                        F[i][j][0]+=F[i][k][0]*F[k+1][j][0];
                    }
            }
        }
        return F[0][n-1][result];
    }
};

