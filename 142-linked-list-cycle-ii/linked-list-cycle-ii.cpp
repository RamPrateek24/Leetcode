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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *s = head;
        ListNode *f = head;
        ListNode *ans = NULL;
        while(f!=NULL && f->next != NULL){
            s = s->next;
            f = f->next->next;
            if(s == f){
                ans = s;
                break;
            }
        }
        if(ans == NULL) return NULL;
        ListNode * p1 = head;
        while(ans->next != NULL && p1->next != NULL){
            if(ans == p1) return p1;
            ans = ans->next;
            p1 = p1->next;   
        }
        return ans;
    }
};