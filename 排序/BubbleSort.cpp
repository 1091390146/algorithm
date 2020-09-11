#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*

*/

/*

*/

/*

*/
void BubbleSort(int arr[], int lo, int hi)
{
    while(lo < (hi = bubble(arr, lo, hi))); //逐趟扫描，直至全序
}
int bubble(int arr[], int lo, int hi){
    int last = lo;//最右侧的逆序对初始化为[lo - 1, lo]
    while(++lo < hi){//自左向右，逐一检查各对相邻元素
        if(arr[lo - 1] > arr[lo]){//若逆序,则
            last = lo; //更新最右侧逆序对位置记录，并交换
            swap(arr[lo - 1], arr[lo]);
        }
    }
    return last;//返回最右侧的逆序对位置
}
//最好O(n)
//最坏O(n^2)
int main(){
   
   system("pause");
   return 0;
}
