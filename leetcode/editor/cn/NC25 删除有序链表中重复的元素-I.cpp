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
     * @param head ListNodeš▒╗
     * @return ListNodeš▒╗
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        ListNode *p = head;
        while (p) {
            ListNode *q = p->next;
            while (q && q->val == p->val) {
                ListNode *r = q->next;
                p->next = r;
                free(q);
                q = r;
            }
            p = p->next;
        }
        return head;
    }
};