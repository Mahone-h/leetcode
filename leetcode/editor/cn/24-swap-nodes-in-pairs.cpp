
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
// 
//
// 示例 2： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 100] 内 
// 0 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你能在不修改链表节点值的情况下解决这个问题吗?（也就是说，仅修改节点本身。） 
// Related Topics 递归 链表 
// 👍 895 👎 0


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
    ListNode* swapPairs(ListNode* head) {
        /**
 * 递归  时间 O(n) 空间O(n)
 */
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        ListNode *newHead = head->next;
//        head->next=swapPairs(newHead->next);
//        newHead->next = head;
//        return newHead;
        /**
         * 迭代 添加一个辅助
         */
        ListNode *tmp = new ListNode;
        tmp->next = head;
        ListNode *p1,*p2;
        head = tmp;
        while (head->next != nullptr && head->next->next != nullptr) {
            p1 = head->next;
            p2 = head->next->next;
            head->next=p2;
            p1->next=p2->next;
            p2->next=p1;
            head=p1;
        }
        return tmp->next;


        return tmp->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}