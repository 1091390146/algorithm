#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <string>

using namespace std;
/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]   

说明：

用返回一个整数列表来代替打印
n 为正整数
*/

/*
解题思路
1、针对本题的常规思路，利用pow函数，秒解
2、假设可能出现大数（本题不可能），转换为大数问题求解
本题自己对于大数解法，分别练习了使用char和string两种方式分别进行求解

通过使用char数组进行求解
通过使用string进行求解
3、递归求解

*/

class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int> res;
		if (n == 0) return res;
		//打印到数组中
		for (int i=1,max=pow(10,n);i<max;i++)
		{
			res.push_back(i);
		}
		return res;
	}
}; 



int main(){
   
   system("pause");
   return 0;
}

//大数版本

#include <cstring>
#include <vector>

class Solution2{
public:
	void printNumbers(int n, int index, string& str, vector<int>& res){
		if(index == n){
			int num = atoi(str.c_str());
			if(num != 0)
				res.push_back(num);
			return;
		}
		for(int i = 0; i < 10; ++i){
			//每一位 从0到9依次排列
			str[index] = i + '0';
			printNumbers(n, index + 1, str, res);
		}
	}

	vector<int> printNumbers(int n){
		vector<int> res;
		string str;
		str.resize(n);
		printNumbers(n, 0, str, res);
		return res;
	}
};