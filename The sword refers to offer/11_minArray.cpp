#include <vector>
#include <stdio.h>

using namespace std;


// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

// 示例 1：

// 输入：[3,4,5,1,2]
// 输出：1
// 示例 2：

// 输入：[2,2,2,0,1]
// 输出：0

//方法1，二分法，时间复杂度O(log(n)),空间复杂度O(1);
class Solution{
public:
    int minArray(vector<int> numbers){
        int size = numbers.size();
        int left = 0;
        int right = size-1;
        if(size==0) return 0;
        if(size==1) return numbers[0];

        while(left < right){
            int mid = (left + right) >> 1;
            if(numbers[mid] > numbers[right])
                left = mid + 1;
            else if(numbers[mid] == numbers[right])
                right--;
            else
                right = mid;
        }
        return numbers[left];
    }
};


// 方法2：
// class Solution {
// public:
//     int minArray(vector<int>& numbers) {
//         for (int i = 1; i < numbers.size(); i ++) 
//             if(numbers[i -1] > numbers[i]) return numbers[i];
//         return numbers[0];
//     }

// };
// 方法3：
// class Solution {
// public:
//     int minArray(vector<int>& numbers) {
//         sort(numbers.begin(), numbers.end());
//         return numbers[0];
//     }
// };




int main(){
    Solution* s = new Solution();
    vector<int> a = {3, 4, 5, 1, 2};
    printf("%d", s->minArray(a));
    // cout << s->minArray(a) << endl;
    getchar();
    return 0;
}