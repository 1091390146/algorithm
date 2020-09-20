#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

/*
面试题 16.22. 兰顿蚂蚁
一只蚂蚁坐在由白色和黑色方格构成的无限网格上。开始时，网格全白，蚂蚁面向右侧。每行走一步，蚂蚁执行以下操作。

(1) 如果在白色方格上，则翻转方格的颜色，向右(顺时针)转 90 度，并向前移动一个单位。
(2) 如果在黑色方格上，则翻转方格的颜色，向左(逆时针方向)转 90 度，并向前移动一个单位。

编写程序来模拟蚂蚁执行的前 K 个动作，并返回最终的网格。

网格由数组表示，每个元素是一个字符串，代表网格中的一行，黑色方格由 'X' 表示，白色方格由 '_' 表示，蚂蚁所在的位置由 'L', 'U', 'R', 'D' 表示，分别表示蚂蚁 左、上、右、下 的朝向。只需要返回能够包含蚂蚁走过的所有方格的最小矩形。

示例 1:

输入: 0
输出: ["R"]
示例 2:

输入: 2
输出:
[
  "_X",
  "LX"
]
示例 3:

输入: 5
输出:
[
  "_U",
  "X_",
  "XX"
]
*/

/*
算法思路：

使用set类型的black来存储所有走过的且变为黑色的地板位置
首先假设起点为数组(0,0)点，后面会根据此进行偏移
black是动态变化的，因为白的能变成黑的，黑的也能变成白的
使用top_left/top_right/top_up/top_down分别记录当前走过的能达到的四个边界
由此可以得到最终结果数组的长宽大小
根据top_left和top_up可以获得数组零点的偏移，即对于black中的(x,y),其对应最终答案中的位置为(top_up-y, x-top_left);
为便于方向的转换，用vector按照顺时针方向记录一个数组{L,U,R,D}
此时，若当前方向为i，则右转下一个方向为(i+1)%4, 左转下一个方向为(i-1+4)%4
为便于下一个位置(x,y)的计算，与该方向数组的下标对应，设置hori/vert分别表示四个方向行走的时候(x,y)的变化情况
初始时，实际实在(1,0)位置，这一点需要注意
运行程序k次，不断更新black。这部分其实是最简单的。
最后计算结果数组的大小, 以及零点的偏移，把black中对应的板砖变黑
组后把当前位置更新上去即可

*/

class Solution {
public:
    vector<string> printKMoves(int K) {
        set<pair<int,int>> black;
        if(K == 0) return vector<string>{"R"};
        vector<char> direction = {'L', 'U', 'R', 'D'};
        vector<int> hori = {-1, 0, 1, 0};
        vector<int> vert = {0, 1, 0, -1};
        int cur_x = 1, cur_y = 0;
        int cur_direction = 2;
        int top_left = 1, top_right = 0;
        int top_up = 0, top_down = 0;
        for(int i = 0; i < K; i++){
            if(black.find(pair<int,int>{cur_x, cur_y}) == black.end()){
                black.insert(pair<int,int>{cur_x, cur_y});
                cur_direction = (cur_direction+1)%4;
            }else{
                black.erase(pair<int,int>{cur_x, cur_y});
                cur_direction = (cur_direction - 1 + 4) % 4;
            }
            cur_x += hori[cur_direction];
            cur_y += vert[cur_direction];
            top_left = min(top_left, cur_x);
            top_right = max(top_right, cur_x);
            top_down = min(top_down, cur_y);
            top_up = max(top_up, cur_y);
        }
        int rows = top_up - top_down + 1;
        int cols = top_right - top_left + 1;
        string t;
        for(int i = 0; i < cols; i++) t.push_back('_');
        vector<string> ans(rows, t);
        for(auto it=black.begin(); it != black.end(); it++){
            int x = it->first, y = it->second;
            ans[top_up-y][x-top_left] = 'X';
        }
        ans[top_up-cur_y][cur_x-top_left] = direction[cur_direction];
        return ans;
    }
};
