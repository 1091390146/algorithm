#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
面试题 16.14. 最佳直线
给定一个二维平面及平面上的 N 个点列表Points，其中第i个点的坐标为Points[i]=[Xi,Yi]。请找出一条直线，其通过的点的数目最多。

设穿过最多点的直线所穿过的全部点编号从小到大排序的列表为S，你仅需返回[S[0],S[1]]作为答案，若有多条直线穿过了相同数量的点，则选择S[0]值较小的直线返回，S[0]相同则选择S[1]值较小的直线返回。

示例：

输入： [[0,0],[1,1],[1,0],[2,0]]
输出： [0,2]
解释： 所求直线穿过的3个点的编号为[0,2,3]
*/
// 记录直线上的点的个数，以及最小的两个编号
struct Record {
  vector<int> ids;
  int cnt;
  Record() : cnt(0) {

  }
};

using LL = long long;

LL gcd(LL a, LL b) {
  LL r;
  do {
    r = a % b;
    a = b;
    b = r;
  } while (r != 0);
  return a;
}

class Solution {
public:
  vector<int> bestLine(vector<vector<int>>& points) {
    // (x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)
    // (y2 - y1) x + (x1 - x2) y = (y2 - y1) * x1 + (x1 - x2) * y1
    int n = points.size();
    map<array<LL, 3>, Record> ABC_ma;

    int best = 0;
    vector<int> ans;

    // 如果A与B和A与C都在一条直线上，那么B与C也在该条直线上
    for (int i = 0; i < n; ++i) {
      vector<int> &pi = points[i];
      int dup = 0; // 与pi位置相同的点数
      ABC_ma.clear();
      int local_best = 0;
      vector<int> local_ans;
      for (int j = i + 1; j < n; ++j) {
        vector<int> &pj = points[j];
        LL A = (LL)pj[1] - pi[1];
        LL B = (LL)pj[0] - pi[0];
        if (A == 0 && B == 0) {
          // pi与pj相同
          ++dup;
          if (local_ans.empty()) local_ans = {i, j};
          continue;
        }
        LL C = A * pi[0] + B * pi[1]; 

        if (A == 0) {
          if (C == 0) {
            B = 1;
          } else {
            LL g = gcd(B, C);
            B /= g;
            C /= g;
          }
        } else if (B == 0) {
          if (C == 0) {
            A = 1;
          } else {
            LL g = gcd(A, C);
            A /= g;
            C /= g;
          }
        } else {
          // A != 0 and B != 0
          LL g = gcd(A, B);
          if (C == 0) {
            A /= g;
            B /= g;
          } else {
            LL w = gcd(g, C);
            A /= w;
            B /= w;
            C /= w;
          }
        }

        Record &r = ABC_ma[{A, B, C}];
        if (r.cnt == 0) {
          r.ids = {i, j};
        }
        ++r.cnt;

      }
      update_ans(ABC_ma, local_best, local_ans);
      local_best += dup;
      if (local_best > best) {
        ans = std::move(local_ans);
        best = local_best;
      }
    }

    return ans;
  }
  template <typename T>
  void update_ans(map<T, Record> &ma, int &best, vector<int> &ans) {
    for (auto &p : ma) {
      Record &r = p.second;
      if (r.cnt > best) {
        best = r.cnt;
        ans = std::move(r.ids);
      } else if (p.second.cnt == best) {
        // 如果穿过相同数量的点
        if (r.ids[0] < ans[0] || (r.ids[0] == ans[0] && r.ids[1] < ans[1])) {
          ans = std::move(r.ids);
        }
      }
    }
  }
};
