#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
   
   system("pause");
   return 0;
}

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int endIndex = arr.size() - 1;
        buildHeap(arr, endIndex);
        while(endIndex){
            swap(arr[0], arr[endIndex]);
            endIndex--;
            heap(arr, 0, endIndex);
        } 
        vector<int> res(k, 0);
        for(int i = 0; i < k; i++){
            res[i] = arr[i];
        }
        return  res;
    }
    //初始化建堆的时间复杂度为O(n)
    void buildHeap(vector<int>& arr, int endIndex){
        for(int i = (endIndex - 1)/2; i >= 0; i--){
            heap(arr, i, endIndex);
        }
    }
    void heap(vector<int>& arr, int startIndex, int endIndex){
        while(true){
            int finalIndex = startIndex;
            if((startIndex * 2 + 1) <= endIndex && arr[finalIndex] < arr[startIndex * 2 + 1])
                finalIndex = startIndex * 2 + 1;
            if((startIndex * 2 + 2) <= endIndex && arr[finalIndex] < arr[startIndex * 2 + 2])
                finalIndex = startIndex * 2 + 2;  
            if(finalIndex == startIndex)
                break;
            swap(arr[startIndex], arr[finalIndex]);
            startIndex = finalIndex;
        }
    }
};
// 重建堆一共需要n-1次循环，每次循环的比较次数为log(i)，则相加为：log2+log3+…+log(n-1)+log(n)≈log(n!)。可以证明log(n!)和nlog(n)是同阶函数：
// 初始化建堆的时间复杂度为O(n)，排序重建堆的时间复杂度为nlog(n)，所以总的时间复杂度为O(n+nlogn)=O(nlogn)。
