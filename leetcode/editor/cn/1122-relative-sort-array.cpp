//给你两个数组，arr1 和 arr2， 
//
// 
// arr2 中的元素各不相同 
// arr2 中的每个元素都出现在 arr1 中 
// 
//
// 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末
//尾。 
//
// 
//
// 示例： 
//
// 
//输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
//输出：[2,2,2,1,4,3,3,9,6,7,19]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr1.length, arr2.length <= 1000 
// 0 <= arr1[i], arr2[i] <= 1000 
// arr2 中的元素 arr2[i] 各不相同 
// arr2 中的每个元素 arr2[i] 都出现在 arr1 中 
// 
// Related Topics 数组 哈希表 计数排序 排序 
// 👍 178 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        //计数排序  先找最大值
        //vector<int> res;
        //int tmp[1001] = {0};
        //for (int &num:arr1) {
        //    tmp[num]++;
        //}
        //for (int &num:arr2) {
        //    while (tmp[num]-- > 0) res.emplace_back(num);
        //}
        //for (int i = 0; i < 1001; ++i) {//剩下的
        //    while (tmp[i]-- > 0) res.emplace_back(i);
        //}
        //return res;


        //hash
        //unordered_map<int,int> map;
        //for (int i = 0; i < arr2.size(); ++i) {
        //    map[arr2[i]] = i;
        //}
        //sort(arr1.begin(), arr1.end(), [&](int num1, int num2) {
        //    if (map.count(num1)) {
        //        return map.count(num2) ? map[num1] < map[num2] : true;
        //    }
        //    return map.count(num2) ? false : num1 < num2;
        //});
        //return arr1;

        //计数排序  先找最大值
        vector<int> res;
        int upper = *max_element(arr1.begin(), arr1.end());
        vector<int> tmp(upper + 1, 0);
        for (int num:arr1) {
            tmp[num]++;
        }
        for (int num:arr2) {
            while (tmp[num]-- > 0) {
                res.emplace_back(num);
            }
        }
        for (int i = 0; i < tmp.size(); ++i) {
            while (tmp[i]-- > 0) {
                res.emplace_back(i);
            }
        }

        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> t1 = {1, 2, 3, 5};
    vector<int> t2 = {2, 1};
    s.relativeSortArray(t1, t2);
    
}