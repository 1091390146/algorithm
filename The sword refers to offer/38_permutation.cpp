#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 38. 字符串的排列
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
*/

/*
https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/hui-su-fa-by-luo-jing-yu-yu/
*/

/*
解题思路一 回溯算法
/*
 * 回溯法
 *
 * 字符串的排列和数字的排列都属于回溯的经典问题
 *
 * 回溯算法框架：解决一个问题，实际上就是一个决策树的遍历过程：
 * 1. 路径：做出的选择
 * 2. 选择列表：当前可以做的选择
 * 3. 结束条件：到达决策树底层，无法再做选择的条件
 *
 * 伪代码：
 * result = []
 * def backtrack(路径，选择列表):
 *     if 满足结束条件：
 *         result.add(路径)
 *         return
 *     for 选择 in 选择列表:
 *         做选择
 *         backtrack(路径，选择列表)
 *         撤销选择
 *
 * 核心是for循环中的递归，在递归调用之前“做选择”，
 * 在递归调用之后“撤销选择”。
 *
 * 字符串的排列可以抽象为一棵决策树：
 *                       [ ]
 *          [a]          [b]         [c]
 *      [ab]   [ac]  [bc]   [ba]  [ca]  [cb]
 *     [abc]  [acb] [bca]  [bac]  [cab] [cba]
 *
 * 考虑字符重复情况：
 *                       [ ]
 *          [a]          [a]         [c]
 *      [aa]   [ac]  [ac]   [aa]  [ca]  [ca]
 *     [aac]  [aca] [aca]  [aac]  [caa] [caa]
 *
 * 字符串在做排列时，等于从a字符开始，对决策树进行遍历，
 * "a"就是路径，"b""c"是"a"的选择列表，"ab"和"ac"就是做出的选择，
 * “结束条件”是遍历到树的底层，此处为选择列表为空。
 *
 * 本题定义backtrack函数像一个指针，在树上遍历，
 * 同时维护每个点的属性，每当走到树的底层，其“路径”就是一个全排列。
 * 当字符出现重复，且重复位置不一定时，需要先对字符串进行排序，
 * 再对字符串进行“去重”处理，之后按照回溯框架即可。
 * */
/*
代码

std::vector<std::string> permutation(std::string s) {
    if(s.empty()){
        return {};
    }

    // 对字符串进行排序
    std::sort(s.begin(), s.end());
    std::vector<std::string> res;
    // 标记字符是否遍历过
    std::vector<bool> visit(s.size(), false);
    std::string track;
    backtrack(res, s, track, visit);

    return res;
}

    /*
     * 回溯函数
     * 使用sort函数对字符串排序，使重复的字符相邻，
     * 使用visit数组记录遍历决策树时每个节点的状态，
     * 节点未遍历且相邻字符不是重复字符时，
     * 则将该字符加入排列字符串中，依次递归遍历。
     * */
/*
void backtrack(std::vector<std::string> &res, std::string s, std::string &track, std::vector<bool> &visit) {
    // 回溯结束条件
    if(track.size() == s.size()){
        res.push_back(track);
        return;
    }

    // 选择和选择列表
    for(int i = 0; i < s.size(); i++){
        // 排除不合法的选择
        if(visit[i]){
            continue;
        }

// 这里可以这么理解, 对于 aab, 记为 "a1a2b", 为了保证不出现重复，我们可以规定一个顺序，当我们需要使用字符 a 的时候，必须先用字符 a1, 后再用字符 a2； 或者当我们需要使用字符a时，必须先用字符a2, 后用字符 a1. 这样就是要保证在生成的字符串排列中不会因为 a1 和 a2 的位置发生对换，而产生新的重复的字符串。
// 我们可以有以下两种方式：
// a1a2b, a1ba2, ba1a2 # 对应 !visit[i-1]
// a2a1b, a2ba1, ba2a1 # 对应 visit[i-1]
// 当使用 visit[i-1]时，若第一个字符就取了 a1, 那么 a2 不会被取，最终循环会被终结终结在 a1b, 不会进入更深的 dfs, 也不会生成解 a1ba2. 对使用 !visit[i-1] 也是同理。
// 这里对于三重复 aaab, 也是成立的。
        if(i > 0 && !visit[i-1] && s[i-1] == s[i]){
            continue;
        }
        visit[i] = true;

        // 做选择
        track.push_back(s[i]);
        // 进入下一次决策树
        backtrack(res, s, track, visit);
        // 撤销选择
        track.pop_back();
        visit[i] = false;
    }
}
解题思路二 交换法————回溯算法
/*
 * 交换法 —— 回溯算法
 *
 * [a, [b, c]]
 * [b, [a, c]] [c, [b, a]]
 *
 * 如上，对字符串"abc"分割，每次固定一个字符为一部分，
 * 其他字符为另一部分，再将固定字符与其他字符进行交换，
 * 依次遍历每个字符，再进行回溯递归。
 * */
/*
代码

std::vector<std::string> permutation2(std::string s) {
    // 去重处理
    std::set<std::string> res;
    backtrack2(s, 0, res);

    return std::vector<std::string>(res.begin(), res.end());
}

    /*
     * 回溯函数
     * 使用set函数对字符串字符进行去重，
     * 使用swap函数交换两个字符
     * */
/*
void backtrack2(std::string s, int start, std::set<std::string> &res) {
    // 回溯结束条件
    if(start == s.size()){
        res.insert(s);
        return;
    }

    for(int i = start; i < s.size(); i++){
        // 做选择
        std::swap(s[i], s[start]);
        // 进入下一次决策树
        backtrack2(s, start+1, res);
        // 撤销选择
        std::swap(s[i], s[start]);
    }
}

*/


int main(){
   
   system("pause");
   return 0;
}
