//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 
//
// 示例 1： 
//
// 
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
// 
//
// 示例 2： 
//
// 
//输入：l1 = [], l2 = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 两个链表的节点数目范围是 [0, 50] 
// -100 <= Node.val <= 100 
// l1 和 l2 均按 非递减顺序 排列 
// 
// Related Topics 递归 链表 
// 👍 1683 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /**
         * 递归
         */
//        if (l1 == nullptr) {
//            return l2;
//        }
//        if (l2 == nullptr) {
//            return l1;
//        }
//        if (l1->val < l2->val) {
//            l1->next = mergeTwoLists(l1->next, l2);
//            return l1;
//        }
//        l2->next = mergeTwoLists(l1,l2->next);
//        return l2;
        /**
         * 迭代
         */
        ListNode *hair = new ListNode();
        ListNode *cur = hair;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next=l1;
                l1 = l1->next;
            } else {
                cur->next=l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1 == nullptr) ? l2 : l1;
        return hair->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}