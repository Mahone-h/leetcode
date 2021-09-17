/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode *dummy = new ListNode(head->val-1);
        dummy->next = head;
        ListNode *cur = head;
        ListNode *pre = dummy;
        while(cur != nullptr && cur->next!=nullptr){

            if(cur->val!=cur->next->val){
                pre = cur;
            }else{
                while(cur->next!=nullptr && cur->val==cur->next->val)//找到相同的最后一个
                    cur = cur->next;
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};