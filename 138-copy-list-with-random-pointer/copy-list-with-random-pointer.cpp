/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp != NULL){
            Node* head2 = new Node(temp->val);
            head2->next = temp->next;
            temp->next = head2;
            temp = temp->next->next;
        }
        Node* temp2 = head;
        while(temp2 != NULL){
            if(temp2->random) temp2->next->random = temp2->random->next;          
            temp2 = temp2->next->next;
        }
        Node* temp3 = head;
        Node* ans = new Node(0);
        Node* tempp = ans;
        while(temp3){
            ans->next = temp3->next;
            temp3->next = temp3->next->next;
            temp3 = temp3->next;
            ans = ans->next;
        }
        return tempp->next;



    }
};