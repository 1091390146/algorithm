// 完全背包问题：一个背包总容量为V，现在有N个物品，第i个 物品体积为weight[i]，价值为value[i]，每个物品都有无限多件，现在往背包里面装东西，怎么装能使背包的内物品价值最大？
// 对比一下，看到的区别是，完全背包问题中，物品有无限多件。往背包里面添加物品时，只要当前背包没装满，可以一直添加。那么状态转移方程为：
// 特点： 每个物品可以无限选用
// f[i+1][j]=max(f[i][j-k*weight[i+1]]+k*value[i+1])，其中0<=k<=V/weight[i+1]

// #include <iostream>
// #include <string.h>
// using namespace std;
// #define Max_n 105
// #define Max_w 10005

// int n,W;
// int w[Max_n],v[Max_n];
// int dp[Max_n][Max_w];

// //初始化
// void initialize(int n,int m)
// {
//     for(int i=0; i<=n; i++)
//         dp[i][0]=0;
//     for(int j=0; j<=W; j++)
//         dp[0][j]=0;
// }

// //dp[i][j]=max⁡{(dp[i][j-k*w[i]]+k*v[i]|0≤k&k*w[i]≤j),dp[i][j-1]}
// void solve_2()
// {
//     for(int i=1; i<=n; i++)
//         for(int j=1; j<=W; j++)
//         {
//             dp[i][j]=dp[i-1][j];
//             for(int k=1; k*w[i]<=j; k++)
//                 dp[i][j]=max(dp[i][j],dp[i][j-k*w[i]]+k*v[i]);
//         }
// }
//时间复杂度和空间复杂度都是o(mn)

// 使用内存为一维数组，伪代码

// for i=1……N

// for j=1……M

// f[j]=max(f[j],f[j-weight[i]+value[i])

// 和01背包问题唯一不同的是j是从1到M。01背包问题是在前一个子问题（i-1种物品）的基础上来解决当前问题（i种物品），向i-1种物品时的背包添加第i种物品；而完全背包问题是在解决当前问题（i种物品），向i种物品时的背包添加第i种物品。
// 代码如下：
#include <iostream>
#include <vector>

using namespace std;
// #define  V 1500
// unsigned int f[V];//全局变量，自动初始化为0
// unsigned int weight[10];
// unsigned int value[10];
// #define  max(x,y)	(x)>(y)?(x):(y)
// int main()
// {
	
// 	int N,M;
// 	cin>>N;//物品个数
// 	cin>>M;//背包容量
// 	for (int i=1;i<=N; i++)
// 	{
// 		cin>>weight[i]>>value[i];
// 	}
// 	for (int i=1; i<=N; i++)
// 		for (int j=1; j<=M; j++)
// 		{
// 			if (weight[i]<=j)
// 			{
// 				f[j]=max(f[j],f[j-weight[i]]+value[i]);
// 			}			
// 		}
	
// 	cout<<f[M]<<endl;//输出最优解
 
// }
int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> weight(N + 1, 0);
	vector<int> value(N + 1, 0);
	vector<int> f(M + 1, 0);
	for(int i = 1; i <= N; ++i){
		scanf("%d %d", &weight[i], &value[i]);
	}
	for(int i = 1; i <= N; ++i)
		for(int j = weight[i]; j <= M; ++j)
			f[j] = max(f[j], f[j - weight[i]] + value[i]);
	return f[M];
}
// 时间复杂度是o(nm),空间复杂度是O(m)