// 多重背包问题
// 容量为10的背包，有5种物品，每种物品数量分别为1，2，1，2，1，其重量分别为5，4，3，2，1，其价值分别为1，2，3，4，5。
// 设计算法，实现背包内物品价值最大。

// #include <iostream>
// #include<algorithm>

// using namespace std;

// int main()
// {
//     int total_weight = 10;
//     int w[6] = { 0,5,4,3,2,1 };
//     int v[6] = { 0,1,2,3,4,5 };
//     int cot[6] = { 0,1,2,1,2,1 };
//     int dp[11] = { 0 };

//     for (int i = 1; i <= 5; i++)
//         for (int k = 1; k <= cot[i];k++)
//             for (int j = 10; j >= w[i]; j--)
//                 dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

//     cout << "总的价值为: " << dp[10] << endl;
//     return 0;
// }
// 复杂度是O(V∗Σp[i]*N)

// 二进制优化
// 下面看另一种思路：
// 如果要表示10，我们刚才是怎样的？
// 一个一个摆出来，像这样：
// 0000000000
// 效率较低。
// 于是我们想到二进制，效率最高：
// 1010
// 一样的道理，如果有101010个同种物品，那么不要拆成1111111111，而是1,2,4,31, 2, 4, 31,2,4,3个。
// 其中3比较特别，而1,2,41, 2, 41,2,4是普通二进制。
// 每一个数都可以表示：

// 1 = 1
// 2 = 2
// 3 = 1+2
// 4 = 4
// 5 = 1+4
// 6 = 2+4
// 7 = 1+2+4
// //已经大于1,2,4可以表示的极限了，该用上3了。
// 8 = 3+1+4
// 9 = 3+2+4
// 10 = 3+1+2+4

// for(int i=1;i<=n;i++)
//     for(int k=1;num[i];k*=2){
//         if(k>num[i]) k=num[i];
//         num[i]-=k;
//         int nw = k*w[i];
//         int nv = k*v[i];
//         for(int j=V;j>=nw;--j)
//             F[j] = max(F[j],F[j-nw] + nv);
//     }
// note：效率较高。是O(N×log∑Num×V)

#include <vector>
#include <algorithm>

using namespace std;

int mult(int n, int m, vector<int>& weight, vector<int>& value, vector<int> nums){
    vector<int> dp(m + 1, 0);
    // for(int i = 1; i <= n ; ++i)
    //     for(int k = 0; k < nums[i]; ++k)
    //         for(int j = m; j >= weight[i]; --j)
    //             dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    for(int i = 1; i <= n; ++i){
        for(int k = 1; nums[i]; k << 1){
            if(k > nums[i])
                k = nums[i];
            nums[i] -= k;
            int nw = k * weight[i];
            int nv = k * value[i];
            for(int j = m; j >= nw; j--)
                dp[j] = max(dp[j], dp[j - nw] + nv);
        }
    }
    return dp[m];
}