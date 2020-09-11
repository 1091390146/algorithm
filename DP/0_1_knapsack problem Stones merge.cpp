// 你有一堆石头质量分别为W1,W2,W3…WN.(W＜＝100000,N <30)现在需要你将石头合并为两堆，使两堆质量的差为最小。
//给一个整数的集合，要把它分成两个集合，要两个集合的数的和最接近
//有一个箱子容量为V（正整数，0≤V≤20000），同时有n个物品（0小于n≤30），每个物品有一个体积（正整数）。要求从n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
 
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> stone(n + 1, 0);
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &stone[i]);
        sum += stone[i];
    }
    vector<int> res(sum / 2 + 1, 0);
               
    for(int i = 0; i <= n; ++i)
        for(int j = sum / 2; j >= stone[i]; --j)
            res[j] = max(res[j], res[j - stone[i]] + stone[i]);
    printf("%d",sum - 2 * res[sum / 2]);
    getchar();
    getchar();
    return 0;
}

//判断是否有和为100的组合 
//注意这里需要判断是01背包还是完全背包，完全背包的话J从左往右遍历即可。
bool findSum100(vector<int>& a) {
        vector<bool> dp(a.size()+1,false);
        dp[0] = true;
        for (int i = 1; i < a.size(); i++) {
            for (int j = 100; j >= a[i]; j--) {
                if (dp[j - a[i]]) {
                    dp[j] = true;
                }
            }
            if (dp[100]) {
                return true;
            }
        }
        return false;
}


//打印和为n的所有组合,DFS法，O(2^n)
void dfs(int current, int sum, int n, vector<int>& nums, vector<int>& path, vector<vector<int>>& list){
    if(sum == n){
        list.push_back(path);
        return;
    }
    if(sum > n || current == nums.size())
        return;
    for(int i = current; i < nums.size(); ++i){
        path.push_back(nums[i]);
        dfs(i + 1, sum + nums[i], n, nums, path, list);
        path.pop_back();
    }
}
