#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 17.22. 单词转换
给定字典中的两个词，长度相等。写一个方法，把一个词转换成另一个词， 但是一次只能改变一个字符。每一步得到的新词都必须能在字典中找到。

编写一个程序，返回一个可能的转换序列。如有多个可能的转换序列，你可以返回任何一个。

示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
["hit","hot","dot","lot","log","cog"]
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
*/

class Solution {
public:

    bool canTranslate(string& from_, string& to_){
        if(from_.size() != to_.size()) { return false; }
        int count = 0;
        for(int i = 0; i < from_.size(); ++i){
            if(from_[i] != to_[i]) {
                count++;
            }
        }
        return count == 1;
    }

    bool hasRoute(string& curWord, string& endWord, vector<string>& wordList, 
                    vector<bool>& visited, vector<string>& result) {
        if(curWord == endWord){ return true; }
        for(int i = 0; i < wordList.size(); ++i){
            if(visited[i] || !canTranslate(curWord, wordList[i])) continue;
            visited[i] = true;
            result.push_back(wordList[i]);
            if(hasRoute(wordList[i], endWord, wordList, visited, result)){
                return true;
            }
            result.pop_back();
            // 如果运行到这一步，意味着无法从i这个点找到路径，所以visited[i]无需改为false.
            // visited[i] = false;
        }
        return false;
    }

    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> result = {beginWord};
        vector<bool> visited(wordList.size(), false);
        if(hasRoute(beginWord, endWord, wordList, visited, result)){
            return result;
        }
        return vector<string>();
    }
};

