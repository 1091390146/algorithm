/*
贪心是一种算法范例，它一点一点地构建解决方案，总是选择下一个提供最明显和最直接好处的部分。因此，选择局部最优也会导致全局解的问题最适合贪心问题。 

例如，考虑分数背包问题。局部最优策略是选择权重比最大的项。这个策略也导致了全局最优解。

假设1元、2元、5元、10元、20元、50元、100元的纸币分别有a,b,c,d,e,f,g张。现在要用这些钱来支付m元，至少要用多少张纸币？用贪心算法的思想,每一次选择最大面值的钱币。
*/

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

using namespace std;

vector<int> Num{ 3,0,2,1,0,3,5 };
vector<int> Value{ 1,2,5,10,20,50,100 };

int BagsQues(int money) {
    int sum = 0;
    for (int i = Value.size() - 1; i >= 0; --i) {
        int N = min(money / Value[i], Num[i]);
        money = money - N * Value[i];
        sum += N;
        if (money == 0)
            return sum;
    }

    return -1;
}

int main()
{
    int money;
    cin >> money;
    int m = BagsQues(money);
    cout << m << endl;

    system("PAUSE");
    return 0;
}

/*
求出每张面额，用了多少张：
*/

// #include <iostream>
// #include <vector>
// #include <tuple>
// #include <algorithm>

// using namespace std;

// vector<int> Num{ 3,0,2,1,0,3,5 }, Value{ 1,2,5,10,20,50,100 };

// vector<tuple<int, int> > BagsQues(int money) {
//     int sum = 0;
//     vector<tuple<int, int> > ch;
//     for (int i = Value.size() - 1; i >= 0; --i) {
//         int N = min(money / Value[i], Num[i]);
//         money = money - N * Value[i];
//         sum += N;
//         if (N != 0) {
//             ch.push_back({ Value[i], N });
//         }
//         if(money == 0)
//             return ch;
//     }
//     ch.clear();
//     ch.push_back({ -1, -1 });
//     return ch;
// }

// int main()
// {
//     int money;
//     cin >> money;
//     vector<tuple<int, int> > m = BagsQues(money);
//     for (int i = 0; i < m.size(); ++i) {
//         cout << get<0>(m[i]) << ":" << get<1>(m[i]) << endl;
//     }

//     system("PAUSE");
//     return 0;
// }