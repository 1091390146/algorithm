#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 08.08. 有重复字符串的排列组合
有重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合。

示例1:

 输入：S = "qqe"
 输出：["eqq","qeq","qqe"]
示例2:

 输入：S = "ab"
 输出：["ab", "ba"]
*/

class Solution {
public:
    vector<string>res;
    vector<string> permutation(string S) {
        string s;
        int n=S.size();
        sort(S.begin(),S.end());//排序使得重复字符相邻
        vector<int>flag(n);
        process(S,s,n,flag);
        return res;
    }
    void process(string S,string& s,int n,vector<int>&flag)
    {
        //终止条件
        if(s.size()==S.size()){
            res.push_back(s);          
        }
        else{
            for(int i=0;i<n;i++){
                if(flag[i]==0){
                    if(i>0&&S[i]==S[i-1]&&flag[i-1]==1)continue;//若有重复字符，跳过该组合
                    s+=S[i];
                    flag[i]=1;
                    process(S,s,n,flag);
                    s.pop_back();//回溯到上一步
                    flag[i]=0;
                }
            }
        }
    }
};