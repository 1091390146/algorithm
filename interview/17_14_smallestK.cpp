#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 17.14. 最小K个数
设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
*/

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size() - 1);
        vector<int> res(k, 0);
        for(int i = 0; i < k; i++){
            res[i] = arr[i];
        }
        return res;
    }
    int getStandard(vector<int>& arr, int i, int j){
        int key = arr[i];
        while(i < j){
            while(i < j && arr[j] >= key)
                j--;
            if(i < j)
                arr[i] = arr [j];
            while(i < j && arr[i] <= key)
                i++;
            if(i < j)
                arr[j] = arr[i];
        }
        arr[i] = key;
        return i;
    }
    void quickSort(vector<int>& arr, int low, int high){
        if(low < high){
            int standard = getStandard(arr, low, high);
            quickSort(arr, low, standard - 1);
            quickSort(arr, standard + 1, high);
        }
    }
};