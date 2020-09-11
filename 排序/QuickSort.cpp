#include <stdio.h>
#include <stdlib.h>
/*
快速排序
1、算法思想
快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，
其中一部分记录的关键字均比另一部分的关键字小，
则可分别对这两部分记录继续进行排序，以达到整个序列有序。

2、实现原理

2.1、设置两个变量 low、high，排序开始时：low=0，high=size-1。
2.2、整个数组找基准正确位置，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面

1、默认数组的第一个数为基准数据，赋值给key，即key=array[low]。
2、因为默认数组的第一个数为基准，所以从后面开始向前搜索（high–），
找到第一个小于key的array[high]，就将 array[high] 赋给 array[low]，
即 array[low] = array[high]。（循环条件是 array[high] >= key；
结束时 array[high] < key）
3、此时从前面开始向后搜索（low++），找到第一个大于key的array[low]，就将 array[low] 赋给 array[high]，即 array[high] = array[low]。（循环条件是 array[low] <= key；结束时 array[low] > key）
4、循环 2-3 步骤，直到 low=high，该位置就是基准位置。
5、把基准数据赋给当前位置。

2.3、第一趟找到的基准位置，作为下一趟的分界点。
2.4、递归调用（recursive）分界点前和分界点后的子数组排序，重复2.2、2.3、2.4的步骤。
2.5、最终就会得到排序好的数组。
*/

int getStandard(int array[], int i, int j) {
	//基准数据 
	int key = array[i];
	while (i < j) {
			//因为默认基准是从左边开始，所以从右边开始比较 
			//当队尾的元素大于等于基准数据 时,就一直向前挪动 j 指针 
			while (i < j && array[j] >= key) {
				j--;
			}
			//当找到比 array[i] 小的时，就把后面的值 array[j] 赋给它 
			if (i < j) {
				array[i] = array[j];
			}
			//当队首元素小于等于基准数据 时,就一直向后挪动 i 指针 
			while (i < j && array[i] <= key) {
				i++;
			}
			//当找到比 array[j] 大的时，就把前面的值 array[i] 赋给它
			if (i < j) {
				array[j] = array[i];
			}
		}
	//跳出循环时 i 和 j 相等,此时的 i 或 j 就是 key 的正确索引位置
	//把基准数据赋给正确位置 
	array[i] = key;
	return i;
}

void QuickSort(int array[], int low, int high) {
	//开始默认基准为 low
	if (low < high) {
		//分段位置下标 
		int standard = getStandard(array, low, high);
		//递归调用排序
		//左边排序 
		QuickSort(array, low, standard - 1);
		//右边排序 
		QuickSort(array, standard + 1, high);
	}
}
/*
5、算法分析

时间复杂度：

最好：O(n log2 n)
最坏：O(n^2)
平均：O(n log2 n)
空间复杂度：O(n log2 n)

稳定性：不稳定
*/

void display(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {
	int array[] = { 49,38,65,97,76,13,27,49,10 };
	int size = sizeof(array) / sizeof(int);
	printf("%d \n", size);
	QuickSort(array, 0, size - 1);
	display(array, size);
	return 0;
}
