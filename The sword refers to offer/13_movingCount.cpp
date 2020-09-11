#include <vector>

using namespace std;

// 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

//  

// 示例 1：

// 输入：m = 2, n = 3, k = 1
// 输出：3
// 示例 2：

// 输入：m = 3, n = 1, k = 0
// 输出：1

//方法一，深度优先遍历
class Solution {
public:
    int digit_sum(int i){
        int sum = 0;
        while(i>0){
            sum += i%10;
            i/=10;
        }
        return sum;
    }
    int dfsSolver(int i, int j, int m, int n, int k, vector<vector<bool>>& vislted){
        if(i>=m||j>=n||digit_sum(i)+digit_sum(j)>k||vislted[i][j]==true) return 0;
        vislted[i][j] = true;
        return 1+dfsSolver(i+1,j,m,n,k,vislted)+dfsSolver(i,j+1,m,n,k,vislted);
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> vislted(m,vector<bool>(n));
        int res = dfsSolver(0,0,m,n,k,vislted);
        return res; 
    }
};
// 复杂度分析

// 时间复杂度：O(mn)

// 空间复杂度：O(mn)



// 方法二：广度优先搜索
// 思路和算法

// 我们将行坐标和列坐标数位之和大于 k 的格子看作障碍物，那么这道题就是一道很传统的搜索题目，我们可以使用广度优先搜索或者深度优先搜索来解决它，本文选择使用广度优先搜索的方法来讲解。

// 那么如何计算一个数的数位之和呢？我们只需要对数 x 每次对 10 取余，就能知道数 x 的个位数是多少，然后再将 x 除 10，这个操作等价于将 x 的十进制数向右移一位，删除个位数（类似于二进制中的 >> 右移运算符），不断重复直到 x 为 0 时结束。

// 同时这道题还有一个隐藏的优化：我们在搜索的过程中搜索方向可以缩减为向右和向下，而不必再向上和向左进行搜索。如下图，我们展示了 16 * 16 的地图随着限制条件 k 的放大，可行方格的变化趋势，每个格子里的值为行坐标和列坐标的数位之和，蓝色方格代表非障碍方格，即其值小于等于当前的限制条件 k。我们可以发现随着限制条件 k 的增大，(0, 0) 所在的蓝色方格区域内新加入的非障碍方格都可以由上方或左方的格子移动一步得到。而其他不连通的蓝色方格区域会随着 k 的增大而连通，且连通的时候也是由上方或左方的格子移动一步得到，因此我们可以将我们的搜索方向缩减为向右或向下。


class Solution {
public:
    int digit_sum(int i){
        int sum = 0;
        while(i>0){
            sum += i%10;
            i/=10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        if(k==0) return 1;
        queue<pair<int,int>> Q;
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        vector<vector<int>> vis(m, vector<int>(n,0));
        vis[0][0] = 1;
        Q.push(make_pair(0,0));
        vis[0][0] = 1;
        int res = 1;
        while(!Q.empty()){
            auto [x,y] = Q.front();
            Q.pop();
            for(int i=0;i<2;i++){
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                if(tx >= m || ty>=n || vis[tx][ty] || digit_sum(tx) + digit_sum(ty) > k) continue;
                vis[tx][ty] = 1;
                res++;
                Q.push(make_pair(tx,ty));
            }
        }
        return res;
    }
};

// 复杂度分析

// 时间复杂度：O(mn)，其中 m 为方格的行数，n 为方格的列数。考虑所有格子都能进入，那么搜索的时候一个格子最多会被访问的次数为常数，所以时间复杂度为 O(2mn)=O(mn)O(2mn)=O(mn)。

// 空间复杂度：O(mn)，其中 m 为方格的行数，n 为方格的列数。搜索的时候需要一个大小为 O(mn)O(mn) 的标记结构用来标记每个格子是否被走过。



// 方法三：递推
// 思路

// 考虑到方法一提到搜索的方向只需要朝下或朝右，我们可以得出一种递推的求解方法。

// 算法

// 定义 vis[i][j] 为 (i, j) 坐标是否可达，如果可达返回 1，否则返回 0。

// 首先 (i, j) 本身需要可以进入，因此需要先判断 i 和 j 的数位之和是否大于 k ，如果大于的话直接设置 vis[i][j] 为不可达即可。

// 否则，前面提到搜索方向只需朝下或朝右，因此 (i, j) 的格子只会从 (i - 1, j) 或者 (i, j - 1) 两个格子走过来（不考虑边界条件），那么 vis[i][j] 是否可达的状态则可由如下公式计算得到：

// 即只要有一个格子可达，那么 (i, j) 这个格子就是可达的，因此我们只要遍历所有格子，递推计算出它们是否可达然后用变量 ans 记录可达的格子数量即可。

// 初始条件 vis[i][j] = 1 ，递推计算的过程中注意边界的处理。


class Solution {
public:
    int get(int i){
        int sum = 0;
        while(i>0){
            sum += i%10;
            i/=10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        if(k==0) return 1;
        vector<vector<int> > vis(m, vector<int>(n, 0));
        int res = 1;
        vis[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 && j == 0) || get(i) + get(j) > k) continue;
                // 边界判断
                if (i - 1 >= 0) vis[i][j] |= vis[i - 1][j];
                if (j - 1 >= 0) vis[i][j] |= vis[i][j - 1];
                res += vis[i][j];
            }
        }
        return res; 
    }
};
// 复杂度分析

// 时间复杂度：O(mn)，其中 m 为方格的行数， n 为方格的列数。一共有 O(mn)个状态需要计算，每个状态递推计算的时间复杂度为 O(1)，所以总时间复杂度为 O(mn)。

// 空间复杂度：O(mn)，其中 m 为方格的行数，n 为方格的列数。我们需要 O(mn)大小的结构来记录每个位置是否可达。

