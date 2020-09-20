#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 08.02. 迷路的机器人
设想有个机器人坐在一个网格的左上角，网格 r 行 c 列。机器人只能向下或向右移动，但不能走到一些被禁止的网格（有障碍物）。设计一种算法，寻找机器人从左上角移动到右下角的路径。



网格中的障碍物和空位置分别用 1 和 0 来表示。

返回一条可行的路径，路径由经过的网格的行号和列号组成。左上角为 0 行 0 列。如果没有可行的路径，返回空数组。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: [[0,0],[0,1],[0,2],[1,2],[2,2]]
解释: 
输入中标粗的位置即为输出表示的路径，即
0行0列（左上角） -> 0行1列 -> 0行2列 -> 1行2列 -> 2行2列（右下角）
*/

class Solution {
public:
    bool dfs(vector<vector<int>>& g, int x, int y, vector<vector<int>>& path) {
        int m = g.size();
        int n = g[0].size();

        if (g[x][y] == 1) return false;

        if (x ==  m - 1 && y == n - 1) {
            path.push_back({x, y});
            return true;
        }

        path.push_back({x, y});
        if (x + 1 < m && dfs(g, x + 1, y, path)) {
            return true;
        }
        if (y + 1 < n && dfs(g, x, y + 1, path)) {
            return true;
        }

        path.pop_back();
        g[x][y] = 1; //不可达
        return false;
    }

    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> path;
        dfs(obstacleGrid, 0, 0, path);
        return path;
    }
};

