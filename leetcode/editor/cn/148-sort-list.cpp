//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 进阶： 
//
// 
// 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
//
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 104] 内 
// -105 <= Node.val <= 105 
// 
// Related Topics 链表 双指针 分治 排序 归并排序 
// 👍 1192 👎 0


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
    ListNode *sortList(ListNode *head) {
        //ListNode *h, *h1, *h2, *pre, *res;
        ////利用h找到该次归并的下一组起点，h1为当前归并组的左起点，h2为右起点
        ////pre作为每次归并的虚设头结点，res为最终结果的虚设头结点
        //
        //int len = 0;
        //h = head;
        //while (h) { //计算链表长度
        //    len++;
        //    h = h->next;
        //}
        //
        //int curr_len = 1; //当前归并目标的长度，当=length时归并结束
        //
        //res = new ListNode(0);
        //res->next = head;
        //
        //while (curr_len < len) {
        //    pre = res;
        //    h = pre->next;
        //    while (h) { //当前长度的归并过程，h为空说明所有结点都遍历完成
        //        int i = curr_len; //寻找左起点和右起点
        //        h1 = h; //左起点
        //
        //        while (i > 0 && h) {
        //            i--;
        //            h = h->next;
        //        }
        //        //没有右节点 不用归并
        //        if (i > 0) { //若由于h为空退出循环，即未找到右起点就已经无剩余结点，那么归并完成
        //            break;
        //        }
        //        h2 = h; //右起点
        //
        //        i = curr_len;
        //        int num2 = 0;
        //        while (i > 0 && h) { //将h移动到该次归并下一组的起点
        //            i--;
        //            h = h->next;
        //            num2++;
        //        }
        //
        //        int num1 = curr_len;
        //        while (num1 > 0 && num2 > 0) { //归并
        //            if (h1->val <= h2->val) {
        //                pre->next = h1;
        //                h1 = h1->next;
        //                num1--;
        //            } else {
        //                pre->next = h2;
        //                h2 = h2->next;
        //                num2--;
        //            }
        //
        //            pre = pre->next;
        //        }
        //
        //        if (num1 > 0) {
        //            pre->next = h1;
        //        } else if (num2 > 0) {
        //            pre->next = h2;
        //        }
        //
        //        while (num1 > 0 || num2 > 0) {//移动到该组末尾
        //            pre = pre->next;
        //            num1--;
        //            num2--;
        //        }
        //
        //        pre->next = h; //连接下一组的起点
        //    }
        //
        //    curr_len *= 2;
        //}
        //
        //
        //return res->next;
        ListNode *h, *h1, *h2, *cur, *res;
        //利用h找到该次归并的下一组起点，h1为当前归并组的左起点，h2为右起点
        //cur 当前归并头结点，res为最终结果的虚设头结点
        int len = 0;
        h = head;
        while (h) { //找长度
            h = h->next;
            len++;
        }
        int cur_len = 1;
        res = new ListNode;
        res->next = head;
        while (cur_len < len) {
            //-1 5 3 4 0为例 cur_len=2
            cur = res;//每次都从头开始归并
            h = cur->next;  //h用来走  cur用来链接
            while (h) { //遍历h开头的
                h1 = h;   //h1=-1
                int i = cur_len;
                while (i > 0 && h) {
                    i--;
                    h = h->next;
                }
                if (i > 0) {//没有第二组
                    break;
                }
                h2 = h; //找到右节点   h2=3
                i = cur_len;
                int num1 = cur_len, num2 = 0;
                while (i > 0 && h) {  // 找到下一组  顺便判断当前第二组长度 h=0
                    i--;
                    h = h->next;
                    num2++;
                }
                //归并 两个有序链表合并
                while (num1 > 0 && num2 > 0) {
                    if (h1->val <= h2->val) {
                        cur->next = h1;
                        h1 = h1->next;
                        num1--;
                    } else {
                        cur->next = h2;
                        h2 = h2->next;
                        num2--;
                    }
                    cur = cur->next;//链接后还得走过去
                }
                cur->next = num1 > 0 ? h1 : h2;
                while (num1 > 0 || num2 > 0) {
                    cur = cur->next;
                    num1--;
                    num2--;
                }
                cur->next = h;  //连接下一组
            }
            cur_len *= 2;
        }
        return res->next;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    ListNode *head = new ListNode;
    vector<int> tmp = {-1, 5, 3, 4, 0};
    ListNode *next = head;
    for (int num:tmp) {
        next->next = new ListNode(num);
        next = next->next;
    }
    s.sortList(head->next);


}