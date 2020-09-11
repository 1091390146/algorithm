#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <string>

using namespace std;
/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/

/*
https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/solution/mian-shi-ti-29-shun-shi-zhen-da-yin-ju-zhen-she-di/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1, x = 0;
        vector<int> res((r + 1) * (b + 1));
        while(1){
            for(int i = l; i <= r; ++i)
                res[x++] = matrix[t][i];
            if(++t > b)
                break;
            for(int i = t; i <= b; ++i)
                res[x++] = matrix[i][r];
            if(--r < l)
                break;
            for(int i = r; i >= l; --i)
                res[x++] = matrix[b][i];
            if(--b < t)
                break;
            for(int i = b; i >= t; --i)
                res[x++] = matrix[i][l];
            if(++l > r)
                break;
        }
        return res;
    }
};
*/


int main(){
   
   system("pause");
   return 0;
}
