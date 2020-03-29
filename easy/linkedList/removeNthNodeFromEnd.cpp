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
    int getLength(ListNode* head){
        int length = 0;
        // Find length
        while (head){
            length++;
            head = head->next;
        }
        
        return length;
    }
    
    ListNode* moveNth(ListNode* head, int n){
        while (n--){
            head = head->next;
        }
        
        return head;
    }
    
    ListNode* removeNextNode(ListNode* head){
        ListNode* nextNode = head->next;
        
        head->next = (nextNode->next)? nextNode->next: NULL;
        delete nextNode;
        
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = head;
        n = getLength(head) - n - 1;
        // Find n-th from head, count from zero
        
        if (n < 0){ // Remove First head  
            dummy->next = head->next;
            delete head;
        }
        else{
            current = moveNth(current, n);
            current = removeNextNode(current);
        }
        
    
        return dummy->next;    
    }
};
