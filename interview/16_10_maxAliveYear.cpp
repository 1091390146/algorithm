#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 16.10. 生存人数
给定N个人的出生年份和死亡年份，第i个人的出生年份为birth[i]，死亡年份为death[i]，实现一个方法以计算生存人数最多的年份。

你可以假设所有人都出生于1900年至2000年（含1900和2000）之间。如果一个人在某一年的任意时期都处于生存状态，那么他们应该被纳入那一年的统计中。例如，生于1908年、死于1909年的人应当被列入1908年和1909年的计数。

如果有多个年份生存人数相同且均为最大值，输出其中最小的年份。

示例：

输入：
birth = {1900, 1901, 1950}
death = {1948, 1951, 2000}
输出： 1901
*/

/*
很多这种类型的题，都是套路了，一个模式。
即使用一个前缀和(积)来保存某i之前所有的状态累计，如此可以求任意两个状态之间的累计。

i        ...0  ...  1  ...  50
生_初始     1       1        1
生_累计     1       2        3


i       ...48 ...  51  ...  100
死_初始     1       1        1
死_累计     1       2        3
*/

class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int> lives(1001, 0), gos(1001,0);
        for(const int &val: birth) lives[val-1900]++;
        for(const int &val: death) gos[val-1900]++;
        for(int i = 1; i < 1001; i++) lives[i] = lives[i-1] + lives[i];
        for(int i = 1; i < 1001; i++) gos[i] = gos[i-1] + gos[i];
        int max_p = lives[0];
        int year = 0;
        for(int i = 1; i < 1001; i++){
            int p = lives[i] - gos[i-1];
            if(max_p < p){
                max_p = p;
                year = i;
            }
        }
        return 1900+year;
    }
};
