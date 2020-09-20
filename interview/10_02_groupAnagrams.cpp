#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

/*
面试题 10.02. 变位词组
编写一种方法，对字符串数组进行排序，将所有变位词组合在一起。变位词是指字母相同，但排列不同的字符串。

注意：本题相对原题稍作修改

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          vector<vector<string>>vec;
          unordered_map<string,vector<int>>map;
          for(int i=0;i<strs.size();i++){
              string tmp=strs[i];
              sort(tmp.begin(),tmp.end());
              map[tmp].push_back(i);
          }
          for(auto it:map){
              auto index=it.second;
              vector<string>res;
              for(auto num:index){
                  res.push_back(strs[num]);
              }
              vec.push_back(res);
          }
        return vec;
    }
};


