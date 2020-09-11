#include <vector>
#include <stdio.h>

// 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

// 示例 1：

// 输入：n = 2
// 输出：2
// 示例 2：

// 输入：n = 7
// 输出：21
// 提示：

// 0 <= n <= 100


// 1.第0级台阶到第1级台 只有一种方法 上1级台阶
// 2.第0级台阶到第2级台 有两种方法 一种是0-2 上2级台阶 一种是上到1级台阶 再上2级台阶
// 3.第0级台阶到第3级台 有两种方法 一种是0-2 再2-3 一种是0-1 1-3 (其中0-1 1-2 2-3已经包含在前面的方法中了)
// 4.逆向来看就是 n台阶的方案数量 = n-1台阶方案数量 + n-2的方案数量
// 总结斐波那契数列：f(n) = f(n - 1) + f(n - 2)



class Solution {
public:
    int fib(int n) {
        //定义具有n+1个整型元素的向量，且给出的每个元素初值为1
        std::vector<int> dp(n+1,1);
        for(int i=2; i<=n;  i++){
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007 ;
        }
        return dp[n];
    }
};

int main(){
    Solution* s = new Solution();
    printf("%d", s->fib(3));
    getchar();
    return 0;
}