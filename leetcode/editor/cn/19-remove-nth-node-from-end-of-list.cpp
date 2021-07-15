//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。 
//
// 进阶：你能尝试使用一趟扫描实现吗？ 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1], n = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2], n = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中结点的数目为 sz 
// 1 <= sz <= 30 
// 0 <= Node.val <= 100 
// 1 <= n <= sz 
// 
// Related Topics 链表 双指针 
// 👍 1448 👎 0


#include "include/headers.h"

using namespace std;

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        /**
         * 因为要走到要删除的节点前  有【1】 这种情况
         * 所有初始化 为slow fast=hair  在1之前
         */
        ListNode *hair = new ListNode(0);
        ListNode *fast = hair, *slow = hair;//从头结点之前走
        hair->next = head;
        n++;
        while (n-- && fast!= nullptr) {//多走一步
            fast = fast->next;
        }
        while (fast != nullptr) { //   走到要删除的节点之前
            fast = fast->next;
            slow = slow->next;
        }
        fast = slow->next;//最少有1个
        slow->next = slow->next->next;
        delete fast;

        ListNode *ret = hair->next;
        delete hair;

        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    s.removeNthFromEnd(head,1);
    delete head;
}