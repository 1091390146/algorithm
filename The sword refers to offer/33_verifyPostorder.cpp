#include <windows.h>

using namespace std;
/*
递归
post的遍历顺序为“左右根”，每一层判断左右子树和根节点的大小关系，如果满足则继续向下判断；否则直接返回失败
具体做法是：
（1）遍历本层数组，找到比根节点(即数组最后一个数)大的第一个节点，此节点向左都是左子树，此节点向右都是右子树
（2）上一步已经把左子树的合法性证实了，只需要证实右子树的合法性，即判断右子树所有值大于根节点。右子树合法则继续下一层判断，否则直接返回false

时间复杂度：O(nlog(n)),最差O(n^2)
空间复杂度：O(log(n)),最差O(n)

*/

/*
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size()-1);
    }
    bool recur(vector<int>& postorder, int left, int right){
        bool ans = true;
        if(left >= right)
            return ans;
        int i = left;
        for(;i < right;i++){
            if(postorder[i]>postorder[right])
                break;
        }
        for(int j = i;j < right;++j){
            if(postorder[j] < postorder[right])
                return false;
        }
        ans = ans && recur(postorder, left, i-1);
        ans = ans && recur(postorder, i, right-1);
        return ans;
    }
};
*/

/*

*/


int main(){
   system("pause");
   return 0;
}
