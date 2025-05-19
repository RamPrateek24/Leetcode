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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1 = 0;
        int count2 = 0;
        if(headA == NULL || headB == NULL) return NULL;
        // ListNode* temp1 = headA;
        // ListNode* temp2 = headB;
        // while(temp1 != NULL){
        //     count1++;
        //     temp1 = temp1->next;
        // }
        // while(temp2 != NULL){
        //     count2++;
        //     temp2 = temp2->next;
        // }
        ListNode* tempp1 = headA;
        ListNode* tempp2 = headB;
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        while(tempp1 != NULL){
            st1.push(tempp1);
            tempp1 = tempp1->next;
        }
        while(tempp2 != NULL){
            st2.push(tempp2);
            tempp2 = tempp2->next;
        }
        ListNode *ans = NULL;
        while(!st1.empty() && !st2.empty()){
            if(st1.top() == st2.top()){
                ans = st1.top();
                st1.pop();
                st2.pop();
            }
            else return ans;
        }
    return ans;
    }
};