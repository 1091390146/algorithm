#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2:

输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
*/

/*
首先，我们正序遍历一次数组，然后在逆序遍历一次数组，然后计算总和就好了。
正序遍历的时候，如果前面位置的分数小过后面的分数（索引值低的为前面），那么后面的位置应该分发的糖果就是前面的+1的和。
逆序的时候，和正序差不多，如果后面位置的分数小过前面的分数（索引值低的为前面），那么前面位置应该分发的糖果就是后面的+1的和；
但是逆序时有一点很关键的时，就是由于我们已经正序遍历过一次数组了，所以前面位置应该分发的糖果会很高，或者很低；
那么这时候我们要判断，后面位置应该分发的糖果数+1 会不会比 前面位置正序遍历过一遍后本来要分发的糖果数还高，如果不会的话，那么就不做任何操作。
反之如果会的话，那就修改前面位置的分发的糖果数。
https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode/
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0;
        vector<int> tmp(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); ++i){
            if(ratings[i] > ratings[i - 1])
                tmp[i] = tmp[i - 1] + 1;
        }
        for(int i = ratings.size() - 1; i > 0; --i){
            if(ratings[i - 1] > ratings[i] && tmp[i - 1] < tmp[i] + 1)
                tmp[i - 1] = tmp[i] + 1;
        }
        for(int i = 0; i < ratings.size(); ++i){
            res += tmp[i];
        }
        return res; 
    }
};

int main(){
   
   system("pause");
   return 0;
}
