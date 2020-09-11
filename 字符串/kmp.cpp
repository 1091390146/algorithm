#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
/*
未改进版:
rank    -1    0   1    2   3   4   5   6   7   8   9
p[]     *     C   H    I   N   C   H   I   L   L   A
next[]  N/A   -1  0    0   0   0   1   2   3   0   0


T   0   0   0   1   0   0   0   0   1   0
P   0   0   0   0   1   0
    -1  0   1   2   3   0

未改进版:
rank    -1  0   1   2   3   4   5
p[]     *   0   0   0   0   1   0
next[]  N/A -1  0   1   2   3   0

    
改进版:
rank    -1  0   1   2   3   4   5
p[]     *   0   0   0   0   1   0
next[]  N/A -1  -1  -1  -1  3   -1

*/

int* buildNext(string P){
    int m = P.size();
    int j = 0;
    int* N = new int[m];
    int t = N[0] = -1;//模式串指针
    while(j < m - 1){
        if(0 > t || P[j] == P[t]){//匹配
            j++;
            t++;
            //N[j] = t; //此句可改进
            N[j] = P[j] != P[t] ? t : N[t];
        }else//失配
        {
            t = N[t];
        }
    }
    return N;
}

int kmpMatch(string T, string P){
    int* next = buildNext(P);//构造next表
    int n = T.size(), i = 0;//文本串指针
    int m = P.size(), j = 0;//模式串指针
    while(i < n && j < m){//自左向右逐个比对字符
        if(0 > j || T[i] == P[j]){//若匹配，或P已移出最左侧(两个判断的次序不可交换)
            i++;
            j++;//则转到下一字符
        }else//否则
        {
            j = next[j];//模式串右移（注意:文本串不用回退）
        }       
    }
    delete[] next;//释放next表
    if(j == m)
        return i - j;
    return -1;
}

int main(){
    string str;
	cout << "Enter the string: ";
	cin >> str;
	string pattern;
	cout << "Enter the pattern: ";
	cin >> pattern;
    
	int result = kmpMatch(str, pattern);
	if (result == -1)
	{
		cout << "Not find pattern words!\n";
	}
	else
	{
		cout << result << endl;
	}
    system("pause");
    return 0;
}

