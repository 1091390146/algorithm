// Description#
// 设有n种不同面值的硬币，各硬币的面值存于数组T［1:n］中。现要用这些面值的硬币来找钱。可以使用的各种面值的硬币个数存于数组Coins［1:n］中。对任意钱数0≤m≤20001，设计一个用最少硬币找钱m的方法。
// 对于给定的1≤n≤10，硬币面值数组T和可以使用的各种面值的硬币个数数组Coins，以及钱数m，0≤m≤20001，编程计算找钱m的最少硬币数。

// Input#
// 输入的第一行中只有1个整数给出n的值,第2行起每行2个数，分别是T[j]和Coins[j]。最后1 行是要找的钱数m。

// Output#
// 输出计算的最少硬币数，问题无解时输出-1。

// #include <bits/stdc++.h>
// using namespace std;
// #define LL long long int
// #define INF 0x3f3f3f3f
// int dp[20020];
// int main(){
//     int i, j, k, n, m;
//     cin >> n;

//     int coins[n];  //硬币个数
//     int T[n];      //硬币面值

//     for(i = 0; i<n; i++)
//         cin >> T[i] >> coins[i];
//     cin >> m;
//     for(i=1;i<=m;i++) dp[i]=INF;    //赋极大值,表示不可达
//     for(i=0;i<n;i++)    //遍历硬币种类
//         for(j=1;j<=coins[i];j++)    //遍历硬币数量
//             for(k=m; k>=T[i]; k--)  //此处较难理解
//                                     //只能是由m到T[i]而不能相反
//                                     //试想,初始态dp[k-T[i]]应当=INF,dp[0]=0
//                                     //如果能组成m元的硬币,那么应当存在一条0->m的路径,此时
//                                     //dp[m]就是需要的硬币数量
//                                     //否则,dp[m]将不能链接到dp[0],从而dp[m]=INF输出-1
//                 dp[k] = min(dp[k], dp[k-T[i]]+1);

//     cout << (dp[m]<m?dp[m]:-1) << endl;
//     getchar();
//     getchar();
//     return 0;
// }
// // 3
// // 1 100
// // 5 20
// // 10 10
// // 100
// 背包总结

// 背包问题实际上代表的是线性规划问题，一般要考虑以下几个因素已决定选取什么样的算法：

// （1） 约束条件，有一个还是两个或者更多个，如果是一个，可能是01背包，完全背包或者多重背包问题，如果有两个约束条件，则可能是二维背包问题。

// （2） 优化目标，求最大值，还是最小值，还是总数(只需将max换成sum)

// （3） 每种物品的个数限制，如果每种物品只有一个，只是简单的01背包问题，如果个数无限制，则是完全背包问题，如果每种物品的个数有限制，则是多重背包问题。

// （4） 背包是否要求刚好塞满，注意不塞满和塞满两种情况下初始值不同。
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> T(n + 1);
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; ++i)
        scanf("%d %d", &T[i], &nums[i]);
    vector<int> dp(m + 1, INF);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int k = 1; nums[i]; k << 1){
            if(k > nums[i])
                k = nums[i];
            nums[i] -= k;
            int nT = k * T[i];
            for(int j = m; j >= nT; --j){
                dp[j] = min(dp[j], dp[j - nT] + k);
            }
        }
    }
    printf("%d", dp[m]);
    getchar();
    getchar();
    return 0;
}