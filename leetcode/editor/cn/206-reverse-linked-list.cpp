//反转一个单链表。 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL 
//
// 进阶: 
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？ 
// Related Topics 链表 
// 👍 1698 👎 0


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
    ListNode* reverseList(ListNode* head) {
        /**
         * 迭代   时间o(n) 空间o(1)
         */
        //ListNode* pre= nullptr;
        //ListNode* curr=head;
        //ListNode* next;
        //while (curr != nullptr) {
        //    next = curr->next;
        //    curr->next=pre;
        //    pre = curr;
        //    curr = next;
        //}
        //return pre;
        /**
         * 递归    时间o(n) 空间o(n)
         */
        if (head== nullptr||head->next== nullptr){
            return head;
        }
        ListNode *pre=reverseList(head->next);
        head->next->next=head;//pre 是头 要改变的是当前层的head->next 的
        head->next= nullptr;
        return pre;
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
    s.reverseList(list);
    
}