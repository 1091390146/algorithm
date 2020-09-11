# include<iostream>
using namespace std;

int binary_search(int arr[],int low , int high, int key)
{
	// 通过递归二分查找 查找元素
	if(low<=high){
		int mid = (high+low) >> 1;
		//若元素在中间 
		if(arr[mid] == key)
			return mid;
		// 若元素比中间的数小 那么它只可能在左边的子数组中 则可另high = mid -1
		else if (arr[mid] > key)
			return binary_search(arr,low,mid-1,key);
        //否则 只可能在右边的子数组汇总 则可令low = mid+1
        return binary_search(arr,mid+1,high,key);  
	}
	// 该元素不在数组中
	return -1;
}
/*
int binary_search(int arr[], int low, int high, int key)
{
	//查找某元素是否存在于数组中 若存在，则返回下标；否则返回-1
	while (low <= high) {
		// 检查key是否在中间
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		// 如果x大于arr[mid] 则low = mid+1;否则high=mid-1
		if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
*/

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;

    //使用sizeof(a)/sizeof(a[0])计算数组的长度；
    //int length = sizeof(a)/sizeof(a[0]);
    // 说明：sizeof()函数可以返回数组所占的内存，而sizeof(a[0])返回的是数组第一个元素所占的内存。
	int n = sizeof(arr) / sizeof(arr[0]);
    cout << n <<endl;
	int result = binary_search(arr, 0, n - 1, x);
	(result == -1) ? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
    getchar();
	return 0;
}

template <typename T> static int binSearch(T* A, T const & e, int lo, int hi){
    while(1 < hi - lo){//有效查找区间的宽度缩短至1时，算法才终止
        auto mi = (lo + hi) >> 1;// 以中点为轴点，经比较后确认深入
        (e < mi) ? hi = mi : lo = mi; //[lo, mi)或[mi, hi)
    }//出口时hi = lo + 1, 查找区间仅含一个元素A[lo]
    return (e == A[lo]) ? lo : -1; //返回命中元素的秩或者-1
}

template <typename T> static int binSearch(T* A, T const & e, int lo, int hi){
    while(lo < hi){
        auto mi = (lo + hi) >> 1;
        (e < A[mi]) ? hi = mi :  lo = mi + 1; //[lo, mi)或(mi, hi)
     }//出口时，A[lo = hi]为大于e的最小元素
     return --lo;//故lo - 1即不大于e的元素的最大秩
}