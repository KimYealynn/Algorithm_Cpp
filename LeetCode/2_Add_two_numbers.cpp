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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode( (l1->val + l2->val)%10);
        ListNode* current_node = result;
        int add = (l1->val + l2->val)/10;

        while( l1->next && l2->next ){
            l1 = l1->next;
            l2 = l2->next;

            current_node-> next = new ListNode ( ( l1->val + l2->val + add )%10 );
            
            current_node = current_node->next;

            add = ( l1->val + l2->val + add ) / 10;
        }
        
        while(l1->next){
            l1 = l1->next;

            current_node -> next = new ListNode ( ( l1->val + add )%10 );
            current_node = current_node->next;

            add = ( l1->val + add ) / 10;
        }
        
        while(l2->next){
            l2 = l2->next;

            current_node -> next = new ListNode ( ( l2->val + add )%10 );
            current_node = current_node->next;

            add = ( l2->val + add ) / 10;
        }
        
        if(add==1)
            current_node->next = new ListNode(1);
        
        return result;
    }
};