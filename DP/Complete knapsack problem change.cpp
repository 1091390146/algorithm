//找零钱问题：有n种面额的硬币，每种硬币无限多，至少用多少枚硬币表示给定的面值M？

// #include <bits/stdc++.h>
// using namespace std;
// #define LL long long int
// #define INF 0x3f3f3f3f
// int dp[20020];
// int main(){
//     int i, j, k, n, m;
//     cin >> n;

//     int T[n];      //硬币面值

//     for(i = 0; i<n; i++)
//         cin >> T[i];
//     cin >> m; //输入要找的零钱money;

//     for(i=1;i<=m;i++) dp[i]=INF;    //赋极大值,表示不可达，注意这里dp[0] = 0;

//     for(i=0;i<n;i++)    //遍历硬币种类
//         for(j=T[i];j<=m;j++)   
                                  
//             dp[j] = min(dp[j], dp[j-T[i]]+1);

//     cout << (dp[m]< m?dp[m]:-1) << endl;
//     return 0;
// }

// #include <algorithm>
// #include <vector>
// #define INF 0x3f3f3f3f

// using namespace std;

// int main(){
//     int n, m;
//     scanf("%d %d", &n, &m);
//     vector<int> coin(n + 1, 0);
//     for(int i = 1; i <= n; ++i){
//         scanf("%d", &coin[i]);
//     }
//     vector<int> dp(m + 1, INF);
//     dp[0] = 0;
//     for(int i = 1; i <= n; ++i)
//         for(int j = coin[i]; j <= m; ++j)
//             dp[j] = min(dp[j], dp[j - coin[i]] + 1);
//     printf("%d", dp[m] <= m ? dp[m] : -1);
//     getchar();
//     getchar();
//     return 0;
// }

// 问题描述

// 100元钱，有几种零钱，比如1元，5元，10元，求有几种组合 : 121种

// 分析

// 时间复杂度O(m*n)，空间复杂度O(n)，完全背包问题

// #include <stdio.h>
// #define N 100
// int a[N + 5];
// int change[4]; //有几种零钱
// //主功能函数，找到一共需要几种零钱
// int findCount(int money, int countOfChange)
// {
//     int i, j;
//     a[0] = 1;
//     for (i = 1; i <= countOfChange; i++)
//     {
//         for (j = change[i]; j <= money; j++)
//         {
//             //核心的代码，就此一句
//             a[j] = a[j] + a[j - change[i]];
//         }
//         /*
//         //去掉注释，可打印每一步的情况
//         for (j = 0; j <= money; j++)
//             printf("%d\t", a[j]);
//         puts("");*/

//     }
//     return a[money];
// }
// int main()
// {
//     int money, num, count, i;
//     money = 6;
//     num = 3;
//     //一系列输入
//     printf("input the money u have: ");
//     scanf("%d", &money);
//     printf("input the kinds of changes: ");
//     scanf("%d", &num);
//     for (i = 1; i <= num; i++)
//     {
//         printf("the %dth change: ", i);
//         scanf("%d", &change[i]);
//     }
//     count = findCount(money, num);
//     printf("the count is %d.\n", count);
//     getchar();
//     getchar();
//     return 0;
// }

#include <vector>
#include <stdio.h>

using namespace std;

int main(){
    int money;
    int n;
    scanf("%d %d", &money, &n);
    vector<int> coin(n + 1);
    vector<int> dp(money + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
        scanf("%d", &coin[i]);
    for(int i = 1; i <= n; ++i){
        for(int j = coin[i]; j <= money; ++j){
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }
    printf("%d", dp[money]);
    getchar();
    getchar();
    return 0;
}