#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
/*
面试题 04.01. 节点间通路
节点间通路。给定有向图，设计一个算法，找出两个节点之间是否存在一条路径。

示例1:

 输入：n = 3, graph = [[0, 1], [0, 2], [1, 2], [1, 2]], start = 0, target = 2
 输出：true
示例2:

 输入：n = 5, graph = [[0, 1], [0, 2], [0, 4], [0, 4], [0, 1], [1, 3], [1, 4], [1, 3], [2, 3], [3, 4]], start = 0, target = 4
 输出 true
*/

class Solution {
    vector<bool> viewed;
    vector<vector<int>> adList;
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        viewed = vector<bool>(n,0);
        adList = vector(n,vector<int>(1,-1));
        for (int i=0;i<graph.size();i++){
            adList[graph[i][0]].push_back(graph[i][1]);
        }
        return search(start,target);
    }

    bool search(int start,int target){
        viewed[start] = 1;
        bool result = 0;
        for(int i=1;i<adList[start].size();i++){
            if (viewed[adList[start][i]]==0){
                if(adList[start][i]==target){
                    viewed[adList[start][i]] =1 ;
                    return 1;
                }
                result = search(adList[start][i],target);
                if(result==1)
                    break;
            }
        }
        return result;
    }

bool search(int start,int target){
    queue<int> q;
    int v;
    viewed[start] =1;
    q.push(start);
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i=1;i<adList[v].size();i++){
            if(viewed[adList[v][i]]==0){
                viewed[adList[v][i]] = 1;
                if(adList[v][i]==target){
                    return 1;
                }
                else{
                    q.push(adList[v][i]);
                }
            }
        }
    }
    return 0;
}

};

