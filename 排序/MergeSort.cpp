#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

/*
归并排序
*/

void merge(vector<int>& arr, int lo, int mi, int hi){
    int* temp = new int[hi - lo + 1];
    int p1 = lo, p2 = mi + 1, i = 0;
    while(p1 <= mi && p2 <= hi){
        temp[i++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
    }
    while(p1 <= mi)
        temp[i++] = arr[p1++];
    while(p2 <= hi)
        temp[i++] = arr[p2++];
    for(int i = 0; i < hi - lo + 1; i++){
        arr[lo + i] = temp[i];
    }
    delete[] temp; 
}

void mergeSort(vector<int>& arr, int lo, int hi){
    if(lo < hi){
        int mi = (lo + hi) >> 1;
        mergeSort(arr, lo, mi);
        mergeSort(arr, mi + 1, hi);
        merge(arr, lo, mi, hi);
    }
}


int main(){
    vector<int> arr;
    int n, temp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    mergeSort(arr, 0, arr.size() - 1);
    for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<endl;
 
    system("pause");
	return 0;

}
