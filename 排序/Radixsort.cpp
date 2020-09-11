#include <iostream>

using namespace std;

int maxbit(int data[], int n){
    int d = 1;
    int p = 10;
    for(int i = 0; i < n; ++i){
        while(data[i] < p){
            p *= 10;
            d++;
        }
    }
    return d;
}

void radixsort(int data[], int n){
    int d = maxbit(data, n);
    int* tmp = new int[n];
    int* count = new int[10];
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; ++i){
        for(j = 0; j < 10; ++j){
            count[j] = 0;
        }
        for(j = 0; j < n; ++j){
            k = (data[j] / radix) % 10;
            count[k]++;
        }
        for(j = 1; j < 10; ++j){
            count[j] = count[j - 1] + count[j];
        }
        for(j = n - 1; j >= 0; --j){
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; ++j){
            data[j] = tmp[j];
        }
        radix *= 10;
    }
    delete[] tmp;
    delete[] count;

}

int main(){
    int i;
    int a[] = {8,2,3,4,3,6,6,3,9};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    cout << "before sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    radixsort(a, ilen); // 桶排序

    cout << "after  sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    getchar();
    return 0;
}
