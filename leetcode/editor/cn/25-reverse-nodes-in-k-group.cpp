//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。 
//
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 进阶： 
//
// 
// 你可以设计一个只使用常数额外空间的算法来解决此问题吗？ 
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2,3,4,5], k = 1
//输出：[1,2,3,4,5]
// 
//
// 示例 4： 
//
// 
//输入：head = [1], k = 1
//输出：[1]
// 
//
// 
// 
//
// 提示： 
//
// 
// 列表中节点的数量在范围 sz 内 
// 1 <= sz <= 5000 
// 0 <= Node.val <= 1000 
// 1 <= k <= sz 
// 
// Related Topics 链表 
// 👍 1058 👎 0


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
    ListNode* reverse(ListNode *head){
        ListNode *pre= nullptr;
        ListNode *curr=head;
        ListNode *next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        return pre;
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        /**
         * 递归
         */
//        if (head == nullptr) {
//            return head;
//        }
//        ListNode *tmp=head;
//        for (int i = 0; i < k-1; ++i) {
//            tmp = tmp->next;
//            if (tmp == nullptr) {
//                return head;
//            }
//        }
//        tmp= reverseKGroup(tmp->next,k);
//        ListNode* pre= tmp;
//        ListNode* curr=head;
//        ListNode* next;
//        while (k-->0) {
//            next = curr->next;
//            curr->next=pre;
//            pre = curr;
//            curr = next;
//        }
//        return pre;

        /**
         * 迭代  1->2->3->4->5
         * pre next
         * pre0  start 1->2 end  next 3
         * 翻转start - end
         */
        ListNode *hair = new ListNode;
        ListNode *pre,*next,*start,*end;
        pre=hair;
        pre->next = head;
        end=pre;
        while (end != nullptr) {
            for (int i = 0; i < k; ++i) {
                end = end->next;
                if (end == nullptr) {
                    return hair->next;
                }
            }
            start = pre->next;
            next = end->next;
            end->next = nullptr;
            pre->next=reverse(start);
            start->next = next;
            pre = start;
            end=pre;
        }
        return hair->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    ListNode *list,*head;
    list=new ListNode(1);
    head=list;

    for (int i = 2; i < 6; ++i) {
        ListNode* tmp=new ListNode(i);
        head->next = tmp;
        head = head->next;
    }
    list=s.reverseKGroup(list, 2);
    while (list != nullptr) {
        cout << list->val<< endl;
        list = list->next;
    }
    
}