#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 17.23. 最大黑方阵
给定一个方阵，其中每个单元(像素)非黑即白。设计一个算法，找出 4 条边皆为黑色像素的最大子方阵。

返回一个数组 [r, c, size] ，其中 r, c 分别代表子方阵左上角的行号和列号，size 是子方阵的边长。若有多个满足条件的子方阵，返回 r 最小的，若 r 相同，返回 c 最小的子方阵。若无满足条件的子方阵，返回空数组。

示例 1:

输入:
[
   [1,0,1],
   [0,0,1],
   [0,0,1]
]
输出: [1,0,2]
解释: 输入中 0 代表黑色，1 代表白色，标粗的元素即为满足条件的最大子方阵
示例 2:

输入:
[
   [0,1,1],
   [1,0,1],
   [1,1,0]
]
输出: [0,0,1]
*/

/*
动态规划，cnt[r][c][0/1]表示以坐标r,c为起点向左/右最多的连续黑色块的数量
*/

class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        vector<int> ans(3, 0);
        int n = matrix.size();
        if(n == 0) return {};
        if(n == 1){
            if(matrix[0][0] == 0)
                return {0, 0, 1};
            else
                return {};
        }
        //cnt[r][c][0/1],0右侧,1下侧
        vector<vector<vector<int>>> cnt(n, vector<vector<int>>(n, vector<int>(2)));
        for(int r = n-1; r >= 0; r--){
            for(int c = n-1; c >= 0; c--){
                if(matrix[r][c] == 1)
                    cnt[r][c][0] = cnt[r][c][1] = 0;
                else{
                    //统计cnt[r][c][0/1]
                    if(r < n-1) cnt[r][c][1] = cnt[r+1][c][1] + 1;
                    else cnt[r][c][1] = 1;

                    if(c < n-1) cnt[r][c][0] = cnt[r][c+1][0] + 1;
                    else cnt[r][c][0] = 1;
				   //更新当前最大子方阵
                    int len = min(cnt[r][c][0], cnt[r][c][1]);//最大的可能的边长
                    while(len >= ans[2]){//要答案r,c最小，所以带等号
                        if(cnt[r+len-1][c][0] >= len && cnt[r][c+len-1][1] >= len){
                            //可以构成长为len的方阵
                            ans = {r, c, len};
                            break;
                        }
                        len--;
                    }
                }
            }
        }
        return ans;
    }
};

