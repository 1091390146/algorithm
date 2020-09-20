#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

/*
面试题 17.26. 稀疏相似度
两个(具有不同单词的)文档的交集(intersection)中元素的个数除以并集(union)中元素的个数，就是这两个文档的相似度。例如，{1, 5, 3} 和 {1, 7, 2, 3} 的相似度是 0.4，其中，交集的元素有 2 个，并集的元素有 5 个。给定一系列的长篇文档，每个文档元素各不相同，并与一个 ID 相关联。它们的相似度非常“稀疏”，也就是说任选 2 个文档，相似度都很接近 0。请设计一个算法返回每对文档的 ID 及其相似度。只需输出相似度大于 0 的组合。请忽略空文档。为简单起见，可以假定每个文档由一个含有不同整数的数组表示。

输入为一个二维数组 docs，docs[i] 表示 id 为 i 的文档。返回一个数组，其中每个元素是一个字符串，代表每对相似度大于 0 的文档，其格式为 {id1},{id2}: {similarity}，其中 id1 为两个文档中较小的 id，similarity 为相似度，精确到小数点后 4 位。以任意顺序返回数组均可。

示例:

输入: 
[
  [14, 15, 100, 9, 3],
  [32, 1, 9, 3, 5],
  [15, 29, 2, 6, 8, 7],
  [7, 10]
]
输出:
[
  "0,1: 0.2500",
  "0,2: 0.1000",
  "2,3: 0.1429"
]
*/

/*
基本思路：
参考《程序员面试金典 英文第6版》，书中620页。注意：第五版没有这题。

先遍历所有文档的所有单词，mp1[word]返回数组，表示包含有单词word的文档id
生成mp1需要O(DW)复杂度，D表示文档数量，W表示每个文档的单词数（粗略认为W相等）。
根据mp1我们就可以判断哪两个文档会相交，只对相交的文档进行相似度计算。即使相似性的计算这块是个暴力法，速度也不会很慢，因为题目说了相交是稀疏的，只有很少的文档有会相交。
知道哪两个文档会相交后，分别排序两个文档内的单词，然后双指针找出两个文档相交元素，进一步的计算出这两个文档的相似度。
进一步提升效率
从判断相交的方法入手。通常的方法是把相交文档内的单词排序，然后双指针找出两个文档相交元素。但是我们可以改进方法，利用好mp1的信息，进一步提升效率。

对于遍历mp1种每个word，都可以得到mp1[word]，这是一个数组，返回包含有单词word的文档id

遍历mp1[word]，对两两文档的相交次数+1，即mp2[id1][id2]++;

最后mp2里存的是所有相交文档的交集个数

相似度(id1,id2) = mp2[id1][id2] / (docs[id1].size() + docs[id2].size() - mp2[id1][id2])

注意：C++注意精度误差问题，最后输出时需要加上1e-9
*/


class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        unordered_map<int, vector<int>> mp1;
        for(int i=0; i<docs.size(); ++i){
            for(auto &word : docs[i]){
                mp1[word].push_back(i);
            }
        }
        unordered_map<int, unordered_map<int, int>> mp2;
        for(auto &item : mp1){
            auto &ids = item.second;
            for(int i=0; i+1<ids.size(); ++i){
                for(int j=i+1; j<ids.size(); ++j){
                    mp2[ids[i]][ids[j]]++;
                }
            }
        }
        
        vector<string> result;
        char temp[256];
        for(auto &item : mp2){
            int id1 = item.first;
            for(auto &item2 : item.second){
                int id2 = item2.first;
                double similary = (double)item2.second / 
                                    (docs[id1].size() + docs[id2].size() - item2.second);
                sprintf(temp, "%d,%d: %0.4lf", id1, id2, similary + 1e-9);
                // cout << temp << endl; // debug
                result.push_back(temp);
            }
        }
        return result;
    }
};
