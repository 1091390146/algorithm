
// 分组背包问题
// 问题
// 有N件物品和一个容量为VV的背包。第i件物品的费用是w[i]，价值是v[i]。这些物品被划分为若干组，每组中的物品互相冲突，最多选一件。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

// 算法
// 这个问题变成了每组物品有若干种策略：是选择本组的某一件，还是一件都不选。也就是说设f[k][j]表示前k组物品花费费用j能取得的最大权值，则有：

// f[k][j]=max(f[k−1][j],f[k−1][j−c[i]]+w[i]∣物品i属于组k)f[k][j]=max(f[k−1][j],f[k−1][j−c[i]]+w[i]∣物品i属于组k)

// 伪代码如下：

// for (所有的组k)
//     for (int j = V; j >= 0; j--)
//         for (所有属于组k的i)
//             f[j] = max{f[j], f[j - w[i]] + v[i]}

// 注意这里的三层循环的顺序，for(j...0)这一层循环必须在for(所有的i属于组k)之外。这样才能保证每一组内的物品最多只有一个会被添加到背包中。
// 另外，显然可以对每组内的物品应用完全背包中“一个简单有效的优化”。
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n , m;//n是多少组,m是重量
    scanf("%d %d", &n, &m);
    vector<int> weight(n + 1, 0);
    vector<int> value(n + 1, 0);
    vector<int> f(m + 1, 0);
    for(int i = 1; i <= n; ++i){
        int s;//s为这一组内数量
        scanf("%d", &s);
        for(int q = 1; q <= s; ++q)
            scanf("%d %d", &weight[q], &value[q]);//输入这一组内重量，价值
        for(int j = m; j > 0; --j){
            for(int k = 1; k <= s; ++k){
                if(j >= weight[k])
                    f[j] = max(f[j], f[j - weight[k]] + value[k]);//最后输出的是f[m],因为每次只保留一组的数据，所以下一组是根据上一组来进行估算,所以在f[m]上每组最多只有一个；
            }
        }
    }
    printf("%d", f[m]);
    getchar();
    getchar();
    return 0;
}
// 3 5
// 2
// 1 2
// 2 4
// 1
// 3 4
// 1
// 4 5


//https://blog.csdn.net/zhaohaibo_/article/details/86177801
