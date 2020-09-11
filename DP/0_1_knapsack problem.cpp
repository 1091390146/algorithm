// 01背包问题：一个背包总容量为V，现在有N个物品，第i个 物品体积为weight[i]，价值为value[i]，现在往背包里面装东西，怎么装能使背包的内物品价值最大？

// 看到这个问题，可能会想到贪心算法，但是贪心其实是不对的。例如最少硬币找零问题，要用动态规划。动态规划思想就是解决子问题并记录子问题的解，这样就不用重复解决子问题了。

// 动态规划先找出子问题，我们可以这样考虑：在物品比较少，背包容量比较小时怎么解决？用一个数组f[i][j]表示，在只有i个物品，容量为j的情况下背包问题的最优解，那么当物品种类变大为i+1时，最优解是什么？第i+1个物品可以选择放进背包或者不放进背包（这也就是0和1），假设放进背包（前提是放得下），那么f[i+1][j]=f[i][j-weight[i+1]+value[i+1]；如果不放进背包，那么f[i+1][j]=f[i][j]。

// 这就得出了状态转移方程：

// 特点：每个物品只有一件供你选择放还是不放

// f[i+1][j]=max(f[i][j],f[i][j-weight[i+1]+value[i+1])。


// #include<iostream>
// using namespace std;
// unsigned int f[10][10];
// unsigned int weight[10];
// unsigned int value[10];
// #define max(x,y) x>y?x:y
// int main(){
//     int N,M;
//     cin>>N;
//     cin>>M;
//     for(int i=1;i<=N;i++){
//         cin>>weight[i]>>value[i];
//     }
//     for(int i=1;i<=N;i++){
//         for(int j=1;j<=M;j++){
//             if(weight[i]<=j){
//                 f[i][j] = max(f[i-1][j],f[i-1][j-weight[i]]+value[i]);
//             }else
//             {
//                 f[i][j] = f[i-1][j];
//             }
            
//         }
//     }
//     cout<<f[N][M]<<endl;
//     getchar();
//     getchar();
//     return 0;
// }

// 时间复杂度和空间复杂度都是o(nm)



// 上面计算f[i][j]可以看出，在计算f[i][j]时只使用了f[i-1][0……j]，没有使用其他子问题，因此在存储子问题的解时，只存储f[i-1]子问题的解即可。这样可以用两个一维数组解决，一个存储子问题，一个存储正在解决的子问题。
// 再进一步思考，计算f[i][j]时只使用了f[i-1][0……j]，没有使用f[i-1][j+1]这样的话，我们先计算j的循环时，让j=M……1，只使用一个一维数组即可。

// for i=1……N

// for j=M……1

// f[j]=max(f[j],f[j-weight[i]+value[i])

// 上面计算f[i][j]可以看出，在计算f[i][j]时只使用了f[i-1][0……j]，没有使用其他子问题，因此在存储子问题的解时，只存储f[i-1]子问题的解即可。这样可以用两个一维数组解决，一个存储子问题，一个存储正在解决的子问题。
// 再进一步思考，计算f[i][j]时只使用了f[i-1][0……j]，没有使用f[i-1][j+1]这样的话，我们先计算j的循环时，让j=M……1，只使用一个一维数组即可。

// for i=1……N

// for j=M……1

// f[j]=max(f[j],f[j-weight[i]+value[i])


// #include<iostream>
// using namespace std;
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
// 		for (int j=M; j>=1; j--)
// 		{
// 			if (weight[i]<=j)
// 			{
// 				f[j]=max(f[j],f[j-weight[i]]+value[i]);
// 			}			
// 		}
	
// 	cout<<f[M]<<endl;//输出最优解
 
// }
// // 时间复杂度是o(nm),空间复杂度是O(m)

// //背包九讲:https://blog.csdn.net/yandaoqiusheng/article/details/84782655

#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	int N;
	int M;
	scanf("%d %d", &N, &M);
	int* weight = new int[N + 1];//C++/C语言没有办法知道指针所指的内存容量，除非在申请内存时记住它。
	int* value = new int[N + 1];
	int* f = new int[M + 1];
	memset(weight, 0, sizeof(weight));
	memset(value, 0, sizeof(value));
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= N; ++i){
		scanf("%d %d", &weight[i], &value[i]);
	}
	for(int i = 1; i <= N; ++i)
		for(int j = M; j >= weight[i]; --j)
			f[j] = max(f[j], f[j - weight[i]] + value[i]);

	printf("%d", f[M]);
	delete[] weight;
	delete[] value;
	delete[] f;
	getchar();
	getchar();
	return 0;
}