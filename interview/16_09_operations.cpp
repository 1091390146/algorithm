#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
面试题 16.09. 运算
请实现整数数字的乘法、减法和除法运算，运算结果均为整数数字，程序中只允许使用加法运算符和逻辑运算符，允许程序中出现正负常数，不允许使用位运算。

你的实现应该支持如下操作：

Operations() 构造函数
minus(a, b) 减法，返回a - b
multiply(a, b) 乘法，返回a * b
divide(a, b) 除法，返回a / b
示例：

Operations operations = new Operations();
operations.minus(1, 2); //返回-1
operations.multiply(3, 4); //返回12
operations.divide(5, -2); //返回-2
*/

/*
有了取反运算以后，减法自然就实现了。乘除法主要是二分的思想（快速乘），再加上一些边界测试用例防止溢出的语句。

给想要真正不抖机灵写下来这道题的同学们一点步骤的建议：

实现取反，测试通过减法
实现快速乘除，测试通过乘除法
根据测试用例，添加防溢出判断

*/

class Operations {
private:
    vector<int> negs, poss; // 存的是[-1, -2, -4...]、[1, 2, 4...]，取反和判断溢出时用
    
    int neg(int a) {
        if(!a) return 0;
        
        int result = 0;
        
        if(a > 0) {
            // 从绝对值最大的部分开始填充
            for(auto p = negs.rbegin(); p != negs.rend(); p++) {   
                if(*p + a < 0) continue;
                
                a += *p;
                result += *p;
            }
        } else {
            for(auto p = poss.rbegin(); p != poss.rend(); p++) {
                if(*p + a > 0) continue;
                
                a += *p;
                result += *p;
            }
        }
        return result;
    }
public:
    Operations() {
        // 构造poss和negs
        int p = 1, n = -1;
        poss.push_back(p);
        negs.push_back(n);
        
        for(int i = 0; i < 30; i++) {
            p += p;
            n += n;
            
            poss.push_back(p);
            negs.push_back(n);
        }
    }
    
    int minus(int a, int b) {
        return a + neg(b);
    }
    
    int multiply(int a, int b) {
        if(!a || !b) return 0;
        if(a == 1) return b;        // 这一步是针对b = INT_MIN的情况，防止下一步取neg时溢出
        if(b < 0) return neg(multiply(a, neg(b))); 
        
        int result = a;
        int times = 1;              // times表示当前结果里已经累加了几个a了
        
        // times < poss[30]是为了防止溢出
        while(times < poss[30] && times + times <= b) {   
            result += result;
            times += times;
        }
        result += multiply(a, minus(b, times));
        
        return result;
    }
    
    int divide(int a, int b) {
        if(!a) return 0;
        
        int result = 1;
        // 只写同号的情况，非同号时用neg转化成同号，但是要注意溢出
        if(a > 0) {
            if(b == INT_MIN) return 0;          // 防止下一句取neg的时候溢出
            if(b < 0) return neg(divide(a, neg(b)));
            if(a < b) return 0;
            
            int acc = b;                        // 不断往acc里填充b，直到acc达到a
            while(acc < poss[30] && a >= acc + acc) {
                result += result;               // result表示已经填充了几个b了
                acc += acc;
            }
            result += divide(minus(a, acc), b);
        } else {
            if(b == 1) return a;                // 防止若a=INT_MIN造成下一句运算时溢出
            if(b > 0) return neg(divide(a, neg(b)));
            if(a > b) return 0;
            
            int acc = b;
            while(acc >= negs[30] && a <= acc + acc) {
                result += result;
                acc += acc;
            }
            result += divide(minus(a, acc), b);
        }
        return result;
    }
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */
