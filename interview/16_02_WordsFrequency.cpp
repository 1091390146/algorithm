#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 16.02. 单词频率
设计一个方法，找出任意指定单词在一本书中的出现频率。

你的实现应该支持如下操作：

WordsFrequency(book)构造函数，参数为字符串数组构成的一本书
get(word)查询指定单词在书中出现的频率
示例：

WordsFrequency wordsFrequency = new WordsFrequency({"i", "have", "an", "apple", "he", "have", "a", "pen"});
wordsFrequency.get("you"); //返回0，"you"没有出现过
wordsFrequency.get("have"); //返回2，"have"出现2次
wordsFrequency.get("an"); //返回1
wordsFrequency.get("apple"); //返回1
wordsFrequency.get("pen"); //返回1
*/

class WordsFrequency {
struct TreeNode{
    int f;
    TreeNode* n[26];
    TreeNode(): f(0){
        for(int i = 0; i < 26; ++i){
            n[i] = NULL;
        }
    }
};
    TreeNode* root;
public:
    WordsFrequency(vector<string>& book) {
        root = new TreeNode();
        for(auto& x: book){
            auto temp = root;
            for(auto& c: x){
                if(!temp->n[c-'a']){
                    temp->n[c-'a'] = new TreeNode();
                }
                temp = temp->n[c-'a'];
            }
            ++(temp->f);
        }
    }
    
    int get(string word) {
        auto temp = root;
        for(auto& c: word){
            if(temp->n[c-'a']) 
                temp = temp->n[c-'a'];
            else 
                return 0;
        }
        return temp->f;
    }
};


/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */