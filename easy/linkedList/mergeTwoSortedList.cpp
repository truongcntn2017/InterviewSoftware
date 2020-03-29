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
    bool isEmpty(ListNode* head){
            return !head;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        
        if (isEmpty(l1) && isEmpty(l2)){
            dummy->next = NULL;
        }
        else{
            ListNode* prev = dummy;
            
            while (!(isEmpty(l1) && isEmpty(l2))){
                if (isEmpty(l2) || (l1 && l2 && l1->val < l2->val)){
                    prev->next = new ListNode(l1->val);
                    l1 = l1->next;
                    prev = prev->next;
                }
                else{
                    prev->next = new ListNode(l2->val);
                    l2 = l2->next;
                    prev = prev->next;
                }     
            }
        }
        
        return dummy->next;
    }
};
