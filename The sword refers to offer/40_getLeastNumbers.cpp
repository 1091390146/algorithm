#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;
/*
剑指 Offer 40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
*/

/*
方法一：排序
思路和算法

对原数组从小到大排序后取出前 k 个数即可。

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) vec[i] = arr[i];
        return vec;
    }
};
复杂度分析

时间复杂度：O(nlogn)，其中 n 是数组 arr 的长度。算法的时间复杂度即排序的时间复杂度。

空间复杂度：O(logn)，排序所需额外的空间复杂度为)O(logn)。
*/

/*
方法二：堆
思路和算法

我们用一个大根堆实时维护数组的前 k小值。首先将前 k个数插入大根堆中，随后从第 k+1个数开始遍历，
如果当前遍历到的数比大根堆的堆顶的数要小，就把堆顶的数弹出，再插入当前遍历到的数。
最后将大根堆里的数存入数组返回即可。
在下面的代码中，由于 C++ 语言中的堆（即优先队列）为大根堆，我们可以这么做。
而 Python 语言中的对为小根堆，因此我们要对数组中所有的数取其相反数，才能使用小根堆维护前 k小值。

此处参考代码为:https://blog.csdn.net/xiaolinnulidushu/article/details/104629479
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
重建堆一共需要n-1次循环，每次循环的比较次数为log(i)，则相加为：log2+log3+…+log(n-1)+log(n)≈log(n!)。可以证明log(n!)和nlog(n)是同阶函数：
初始化建堆的时间复杂度为O(n)，排序重建堆的时间复杂度为nlog(n)，所以总的时间复杂度为O(n+nlogn)=O(nlogn)。

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int>vec(k, 0);
        if (k == 0) return vec; // 排除 0 的情况
        priority_queue<int>Q;
        for (int i = 0; i < k; ++i) Q.push( arr[i]);
        for (int i = k; i < (int)arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};
复杂度分析

时间复杂度：O(nlogk)，其中 n是数组 arr 的长度。由于大根堆实时维护前 k小值，所以插入删除都是 O(\log k)O(logk) 的时间复杂度，最坏情况下数组里 nn 个数都会插入，所以一共需要O(nlogk) 的时间复杂度。

空间复杂度：O(k)，因为大根堆里最多 k个数。

快排
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
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
*/

int main(){
   
   system("pause");
   return 0;
}
