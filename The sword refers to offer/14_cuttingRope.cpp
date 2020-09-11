#include<cmath>

#include<vector>
#define max(a,b)  ((a)>(b)?(a):(b))  
using namespace std;

// 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

// 示例 1：

// 输入: 2
// 输出: 1  
// 解释: 2 = 1 + 1, 1 × 1 = 1
// 示例 2:

// 输入: 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        int a = n/3,b = n%3;
        if(b==0) return pow(3,a);
        if(b==1) return pow(3,a-1)*4;
        return pow(3,a)*2;
    }
};


//运用完全背包问题去解
// 首先要找准动态规划的公式，比较容易想到的是 dp[i]=max(dp[i],dp[j]*dp[i-j]);但有个细节就是绳子存在不被切割但情况，在i比较小的时候if(i!=n) dp[i] = max(dp[i],i);式子尤为关键！
class Solution2 {
public: 
int cuttingRope(int n) {
    vector<int> dp(n+1,0);
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i] = max(dp[i],dp[j]*dp[i-j]);
        }
        if(i!=n) dp[i] = max(dp[i],i);
    }
    return dp[n];
}   
};

