#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <stack>
#include <string>

using namespace std;

void insertSort(int a[], int size){
    for(int i = 0; i < size - 1; ++i){
        int temp = a[i + 1];
        int j = i;
        while(j>=0 && temp < a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int main(){
   
   system("pause");
   return 0;
}
