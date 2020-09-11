/*
假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。

示例 1:

输入: flowerbed = [1,0,0,0,1], n = 1
输出: True
示例 2:

输入: flowerbed = [1,0,0,0,1], n = 2
输出: False
*/
/*
贪心
我们从左到右扫描数组 flowerbed，如果数组中有一个 0，并且这个 0 的左右两侧都是 0，那么我们就可以在这个位置种花，即将这个位置的 0 修改成 1，并将计数器 count 增加 1。对于数组的第一个和最后一个位置，我们只需要考虑一侧是否为 0。

在扫描结束之后，我们将 count 与 n 进行比较。如果 count >= n，那么返回 True，否则返回 False
首先为了避免首位和尾位的特殊情况，可在首位和尾位都填上一个0，这样就可以一视同仁了，只需寻找到有多少个 0 的左右两边都是0即可，该个数即为可插花朵的最大值
*/

#include <iostream>
#include <vector>
#include <algorithm>    
#include <cstring>
#include <cstdio>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.insert(flowerbed.end(),0);
        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0){
                flowerbed[i]=1;
                count++;
            }
            if(count>=n)
                return true;
        }
        return n<=count;
    }
};
