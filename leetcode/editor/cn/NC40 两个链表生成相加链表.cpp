/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */

    ListNode* reverse(ListNode* head) {
        ListNode* pre= nullptr;
        ListNode* curr=head;
        ListNode* next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next=pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    /**
     * 需要翻转 有的不需要翻转 则直接相加
     * @param head1
     * @param head2
     * @return
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        if(head1==nullptr) return head2;
        if(head1==nullptr) return head1;
        head1=reverse(head1);
        head2=reverse(head2);
        ListNode *head=new ListNode(0);
        ListNode *next=head;
        int sum=0;
        while(head1!=nullptr || head2!=nullptr){
            if(head1!=nullptr){
                sum+=head1->val;
                head1=head1->next;
            }
            if(head2!=nullptr){
                sum+=head2->val;
                head2=head2->next;
            }
            next->next=new ListNode(sum%10);
            next=next->next;
            sum=sum/10;
        }
        if(sum!=0){
            next->next=new ListNode(sum%10);
        }
        next=head->next;
        delete head;
        return reverse(next);

    }
};