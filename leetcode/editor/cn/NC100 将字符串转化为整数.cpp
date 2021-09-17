class Solution {
public:
    int atoi(const char *str) {
        if(strlen(str)==0) return 0;// 1. 空字符串
        int i=0,res=0,flag=1;
        while(str[i]==' ') i++;  // 2. 忽略前置0
        // 3. 记录符号
        if(str[i]=='-'){
            flag=-1;
            i++;
        }
        if(str[i]=='+') i++;
        for(;i<strlen(str);i++){
            // 4. 处理非法值
            if(str[i]<'0'||str[i]>'9') break;
            // 5. 处理溢出
            if(res > INT_MAX/10 || (res ==INT_MAX/10 && str[i]==INT_MAX % 10))
                return flag==1?INT_MAX:INT_MIN;
            res=res*10+str[i]-'0';
        }
        return res*flag;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // write code here
    ListNode *head=new ListNode(0);
    ListNode *next=head;
    int sum=0;
    while(l1!=nullptr ||l2!=nullptr ){
        if(l1!=nullptr){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=nullptr){
            sum+=l2->val;
            l2=l2->next;
        }
        next->next=new ListNode(sum % 10);
        next=next->next;
        sum=sum/10;
    }
    if(sum!=0){
        next->next=new ListNode(sum);
    }
    next=head->next;
    delete head;
    return next;