#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

//  

// 示例 1：

// 输入：s = "We are happy."
// 输出："We%20are%20happy."
//  

class Solution{
public:
    string replaceSpace(string s){
        string res;
        for(auto c : s){
            if(c == ' ')
                res += "%20";
            else
                res += c;
        }
        return res;
    }
};

// 复杂性分析

// 时间复杂度：O(n)。遍历字符串 s 一遍。
// 空间复杂度：O(n)。额外创建字符数组，长度为 s 的长度的 3 倍

int main(){
    string str;
    Solution s;
    str.resize(100);
    scanf("%[^\n]", &str[0]);
    // getline(cin, str);
    //cin接收输入时，:>> 是会过滤掉不可见字符（如 空格 回车，TAB 等）；从第一个非空白符开始读，知道空白符或文件结束为止
    //可以用getline：
    str = s.replaceSpace(str);
    printf("%s", str.c_str());
    // cout << s.replaceSpace(str) << endl;
    system("pause");
    return 0;
}