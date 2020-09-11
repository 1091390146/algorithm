#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"、"-1E-16"及"12e+5.4"都不是。

*/
/*
https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/solution/mian-shi-ti-20-biao-shi-shu-zhi-de-zi-fu-chuan-y-2/
*/
/*
class Solution {
public:
	bool isNumber(string s) {
		vector<map<char, int>> states;
		map<char, int> temp;
		// s代表sign，正负号
		// d代表digit，数字

		// 所有表之外的状态转移即为非法数字

		// 0，头部空格状态
		temp[' '] = 0;  // 输入 空格 还是 空格状态0
		temp['s'] = 1;  // 输入 正负号 进入 符号状态1
		temp['d'] = 2;  // 输入 数字 进入 小数点前数字状态2
		temp['.'] = 4;	// 输入 小数点 进入 前为空小数点后首位数字状态4
		states.push_back(temp);
		temp.clear();
		// 1，符号状态
		temp['d'] = 2;  // 输入 数字 进入 小数点前的数字状态2
		temp['.'] = 4;  // 输入小数点 进入 前为空小数点后首位数字状态4
		states.push_back(temp);
		temp.clear();
		// 2，小数点前数字状态
		temp['d'] = 2;  // 输入 数字 还是 小数点前的数字状态2
		temp['.'] = 3;  // 输入 小数点 进入 前非空小数点后的数字状态3
		temp['e'] = 5;	// 输入 e 进入 指数符号状态5
		temp[' '] = 8;	// 输入 空格 进入 尾部空格状态8
		states.push_back(temp);
		temp.clear();
		// 3，前非空小数点后的数字状态
		temp['d'] = 3;	// 输入 数字 还是 前非空小数点后的数字状态3
		temp['e'] = 5;	// 输入 e 进入 指数符号状态5
		temp[' '] = 8; 	// 输入 空格 进入尾部空格状态8
		states.push_back(temp);
		temp.clear();
		// 4，前为空小数点后首位数字状态4
		temp['d'] = 3; 	// 输入 数字 进入 前非空小数点后的数字状态3
		states.push_back(temp);
		temp.clear();
		// 5，指数符号状态5
		temp['s'] = 6;  // 输入 正负号 进入 指数后的符号状态6
		temp['d'] = 7;	// 输入 数字 进入 指数位置数字状态7
		states.push_back(temp);
		temp.clear();
		// 6，指数后的符号状态
		temp['d'] = 7;  // 输入 数字 进入 指数位置数字状态7
		states.push_back(temp);
		temp.clear();
		// 7，指数位置数字状态
		temp['d'] = 7;  // 输入 数字 还是 指数位置数字状态7
		temp[' '] = 8;  // 输入 空格 进入 尾部空格状态8
		states.push_back(temp);
		temp.clear();
		// 8，尾部空格状态
		temp[' '] = 8;  // 输入 空格 还是 尾部空格状态8
		states.push_back(temp);
		temp.clear();
		
		// 初始状态，在0状态
		int p = 0;
		// 状态转移的输入key
		char t;
		// 逐字符
		for (int i = 0; i < s.length();i++) {
			char c = s[i];
			// 如果是数字，key='d'
			if (c >= '0'&&c <= '9') {
				t = 'd';
			}
			// 如果是正负号，key='s'
			else if (c == '+' || c == '-') {
				t = 's';
			}
			// 如果是其他字符，key='c'，包含了'.' ' ' 其他非法字符
			else {
				t = c;
			}
			map<char, int>::iterator it = states[p].find(t);
			// 如果找不到这个状态转移，则非法数字
			if (it == states[p].end()) {
				return false;
			}
			// 如果找到，获取转移后的状态
			p = (int)it->second;
		}
		// 是否在允许结尾的状态2 3 7 8
		return p == 2 || p == 3 || p == 7 || p == 8;
	}
};
*/

// 《剑指Offer》中思路，C++实现，感觉这个代码量很少（去掉注释的话），思路很清楚。有详细注释。实在不清楚翻翻书。

class Solution {
private:
    // 整数的格式可以用[+|-]B表示, 其中B为无符号整数
    bool scanInteger(const string s, int& index){

        if(s[index] == '+' || s[index] == '-')
            ++index;

        return scanUnsignedInteger(s, index);
    }
    
    bool scanUnsignedInteger(const string s, int& index){

        int befor = index;
        while(index != s.size() && s[index] >= '0' && s[index] <= '9')
            index ++;

        return index > befor;
    }
public:
    // 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
    // 其中A和C都是整数（可以有正负号，也可以没有），而B是一个无符号整数
    bool isNumber(string s) {

        if(s.size() == 0)
            return false;
        int index = 0;

        //字符串开始有空格，可以返回true
        while(s[index] == ' ')  //书中代码没有该项测试
            ++index;

        bool numeric = scanInteger(s, index);

        // 如果出现'.'，接下来是数字的小数部分
        if(s[index] == '.'){

            ++index;

            // 下面一行代码用||的原因：
            // 1. 小数可以没有整数部分，例如.123等于0.123；
            // 2. 小数点后面可以没有数字，例如233.等于233.0；
            // 3. 当然小数点前面和后面可以有数字，例如233.666
            numeric = scanUnsignedInteger(s, index) || numeric;
        }

        // 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
        if(s[index] == 'e' || s[index] == 'E'){

            ++index;

            // 下面一行代码用&&的原因：
            // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
            // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
            numeric = numeric && scanInteger(s ,index);
        }

        //字符串结尾有空格，可以返回true
        while(s[index] == ' ')
            ++index;
			
        return numeric && index == s.size();
    }
};

int main(){

	string str;
	cin >> str;
	Solution* s = new Solution();
	cout << s->isNumber(str);
   
   system("pause");
   return 0;
}
