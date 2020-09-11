#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <string>

using namespace std;
/*
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
*/

/*
思路描述：因为不用考虑大数问题，所以只需要循环地去计算就可以了，但是单纯的循环去算，比如：


for(int i = 1; i < n; i ++)
	x *= x;
是会超时的。

所以我们可以考虑比如我们计算 x^8，就是 x^2 * x^2 * x^2 * x^2，当我们计算出来 x^2 之后就可以只进行三次乘法就可以了，相对于之前的 7 次乘法，时间大大减少了。

也就是 x^n 可以分解成若干个 x^i 的乘积

我们这里使用快速幂进行求解。我们看一下 n 的二进制形式一定是若干个 1 和 0 构成，比如 9 = 1001 = 1*2^3 + 0*2^2 + 0*2^1 + 1*2^0

x^9 = x^[2^0] * x^[2^1 * 0] * x^[2^2 * 0] * x^[2^3];
所以我们可以看出来，每次乘的值都是前一个值的2倍，当 n 对应位为0时跳过

负数幂和正数幂相同，因为除以一个数就相当于乘这个数的倒数。
*/

class Solution{
public:
    double myPow(double x, int n){
        if(x == 1 || n == 0)
            return 1;
        double ans = 1;
        long num = n;
        if(n < 0){
            num = -num;
            x = 1 / x;
        }
        while(num){
            if(num & 1)
                ans *= x;
            x *= x;
            num >>= 1;
            printf("%f %ld\n", ans, num);
/*
在printf中%d用于int或者比int小的整数类型。比int小的类型被转型成int。

%ld用于long类型，%lld用于long long类型。

%x标识的数会被当成int进行读取，所以long long类型的数如果超过int的范围会被截断，得不到正确的结果。而且因为它多占了4个字节，还会影响后面的其它标识符的输出。

另外%f标识的数会被当成double读取，即取出8个字节读取。
*/
        }
        return ans;
    }
};

int main(){
    Solution* s = new Solution();
    double x;
    int n;
    /*
    注意scanf函数和printf函数是不同寻常的函数，因为它们都没有将函数的参数限制为固定数量。scanf函数和printf函数又可变长度的参数列表。当调用带可变长度参数列表的函数时，编译器会安排float参数自动转换成为double类型，其结果是printf函数无法区分float型和double型的参数。因此在printf函数调用中%f既可以表示float型又表示double型的参数。

    另一方面，scanf函数是通过指针指向变量的。%f告诉scanf函数在所传地址位置上存储一个float型值，而%lf告诉scanf函数在所传地址位置上存储一个double型值。这里float和double的区别是非常重用的。如果给出了错误的转换说明，那么scanf函数将可能存储错误的字节数量（没有提到的是，float型的为模式可能不同于double型的位模式）。
    https://blog.csdn.net/shenzhou111/article/details/7826444
    */
    scanf("%lf %d", &x, &n);
    printf("%f", s->myPow(x, n));
    getchar();
    getchar();
    return 0;
}