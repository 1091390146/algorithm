#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
面试题 16.21. 交换和
给定两个整数数组，请交换一对数值（每个数组中取一个数值），使得两个数组所有元素的和相等。

返回一个数组，第一个元素是第一个数组中要交换的元素，第二个元素是第二个数组中要交换的元素。若有多个答案，返回任意一个均可。若无满足条件的数值，返回空数组。

示例:

输入: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
输出: [1, 3]
示例:

输入: array1 = [1, 2, 3], array2 = [4, 5, 6]
输出: []
*/

/*
sum_a - x = sum_b + x
sum_a - sum_b = 2 * x
即: 两数组和 之差必须为偶数,才可能交换, 否则返回 [ ]
确定数组和差 为 (diff = sum_a - sum_b) // 2,
遍历其中一个,在另一个中查找即可. 转为 两数之和,一样的解法.
*/

class Solution {
public:
   vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        set<int>s;
        int sum1=0,sum2=0;
        for(int i=0;i<array1.size();i++)
            sum1+=array1[i];
        for(int i=0;i<array2.size();i++){
            sum2+=array2[i];
            s.insert(array2[i]);     
        }
        if(abs(sum2-sum1)%2==1)     //abs取绝对值
           return {};                      //奇数直接返回空数组
        int n=(sum2-sum1)/2;                //体会一下这里n如果是负数会怎样
        for(int i=0;i<array1.size();i++){
            if(s.find(array1[i]+n)!=s.end())      //找到了就返回这俩数就行了
                return {array1[i],array1[i]+n}; //这里用array[i]+n代替array2里需要交换的数，秒！
        }
        return {};      //没找到返回空数组
    }
};