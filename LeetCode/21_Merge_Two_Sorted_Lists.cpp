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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root = NULL;
        ListNode* L = new ListNode(0);
        root = L;
        
        while(l1 != NULL and l2 !=NULL){
            if(l1->val > l2->val){
                L->next = new ListNode(l2->val);
                l2 = l2->next;
                L = L->next;
            }
            else if(l1->val < l2->val){
                L->next = new ListNode(l1->val);
                l1 = l1->next;
                L = L->next;
            }
            else if(l1->val == l2->val){
                L->next = new ListNode(l1->val);
                L = L->next;
                L->next = new ListNode(l2->val);
                L = L->next;
                l1 = l1->next;
                l2 = l2->next;           
            }
        }
    
        if(l1 != NULL) {
            L->next = l1;
            L = L->next;
        }
        if(l2 != NULL) {
            L->next = l2;
            L = L->next;
        }
        
        return root->next;
    }
};