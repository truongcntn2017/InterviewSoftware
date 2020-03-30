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
    bool isFull(ListNode* head){
            return !head;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        dummy->next = NULL;
        
        if (l1 || l2){
            ListNode* prev = dummy;
            
            while (l1 || l2){
                if (isFull(l2) || (l1 && l2 && l1->val < l2->val)){
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
