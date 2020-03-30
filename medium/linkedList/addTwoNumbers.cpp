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
    void updateValue(int& value, int& remainder){
        remainder = value /10;
        value %= 10;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        int remainder, value;
        remainder = value = 0;
        
        while (l1 || l2){
            value = remainder;
            value += (l1) ? l1->val : 0;
            value += (l2) ? l2->val : 0;
            
            updateValue(value, remainder);
            prev->next = new ListNode(value);
            
            prev = prev->next;
            l1 = (l1) ? l1->next : l1;
            l2 = (l2) ? l2->next : l2;
        }
        // Adding remainder = 1
        if (remainder){
            prev->next = new ListNode(remainder);
            prev = prev->next;
        }
        
        return dummy->next;
    }
};
