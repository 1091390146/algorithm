#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 08.01. 三步问题
三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。

示例1:

 输入：n = 3 
 输出：4
 说明: 有四种走法
示例2:

 输入：n = 5
 输出：13
*/
class Solution {
public:
    int waysToStep(int n){
        if(n <= 2) return n;
        if (n == 3) return 4;
        int a = 1,b=2,c=4,d;
        for (int i = 4; i <= n; i++){
            d = ((a+b)%1000000007+c)% 1000000007;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};