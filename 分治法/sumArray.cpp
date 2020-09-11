#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
求一个组数的和，减治法：将区间分为一个大部分和小部分，逐步蚕食小部分;
sum(int a[], int n){
    return (n < 1) ? 0 : sum(a, n - 1) + a[n - 1];
}
线性递归O(n);

数组倒置:
递归：
void reverse(int* a, int low, int high){
    if(low < high){
        swap(a[low], a[high]);
        reverse(a, low + 1, high - 1);
    }
}

迭代:
while(low < high){
    swap(a[low++], a[high--]);
}
*/

/*
分治法:
将其划分为若干个(通常两个子问题),规模大体相当
分别求解子问题
由子问题的解得到原问题的解

数组求和:二分递归
int sum(int a[], int low, int high){
    if(low == high)
        return a[low];
    int mi = (low + high) >> 1;
    return sum(a, low, mi) + sum(a, mi+1, high); 
}
T(n) = 各层递归所需要的的时间总和
     = O(1) * (2^0 + 2^1 + ... + 2^(log(n)))
     = O(1) * (2^(log(n)+1)-1) 
     = O(n)


max2:从数组区间a[low, high)中找出最大的两个整数A[x1]和a[x2] //a[x1] >= a[x2]
     元素比较的次数，要求尽可能的小

迭代:
void max2(int a[], int low, int high, int& x1, int& x2){
    for(x1 = low, int i = low + 1; i < high; i++){
        if(a[x1] < a[i])
            x1 = i;
    }
    for(x2 = low, int i = low + 1; i < x1; i++){
        if(a[x2] < a[i])
            x2 = i;
    }
    for(int i = x1+1; i < high; i++){
        if(a[x2] < a[i])
            x2 = i;
    }
}
无论如何,比较次数总是2n-3;

改进迭代:
void max2(int a[], int low, int high, int& x1, int& x2){
    if(a[x1 = low] < a[x2 = low + 1])
        swap(x1, x2);
    for(int i = low + 2; i < high; i++){
        if(a[x2] < a[i])
            if(a[x1] < a[x2 = i])
                swap(x1, x2);
    }
}
最坏情况也是2n-3

递归 + 分治
void max2(int a[], int low, int high, int& x1, int& x2){
    if(low + 2 == high){
        ...;
        return; //T(2) = 2;
    }
    if(low + 3 == high){
        ...;
        return; //T(3) <= 3;
    }
    int mi = (low + high)/2; //divide
    int x1l, x2l;
    max2(a, low, mi, x1l, x2l);
    int x1r, x2r;
    max(a, mi, high, x1r, x2r);
    if(a[x1l] > a[x1r]){
        x1 = x1l;
        x2 = (a[x2l] > a[x1r]) ? x2l : x1r;
    }else{
        x1 = x1r;
        x2 = (a[x1l] > a[x2r]) ? x1l : x2r;
    }//1 + 1 = 2;
} //T(n) = 2 * T(n/2) + 2 <= 5n/3 - 2

最坏的情况是5n/3 - 2,因为最坏的情况就是每一组分成3个，最后会形成n/3个，
而第一层到倒数第二层执行的次数只有两次，因为是2分，所以为2 * (2^(log(3/n/2) + 1) - 1)
最后一层操作为3,所以 n/3 * 3,最后总和为5n/3 - 2;
*/


int main(){
   system("pause");
   return 0;
}
