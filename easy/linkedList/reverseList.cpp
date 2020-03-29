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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* nextNode = head;
        ListNode* current = NULL;
        ListNode* prevNode;
        
        if (nextNode){
            while (nextNode){
                prevNode = current;
                current = nextNode;
                nextNode = nextNode->next;
                
                current->next = prevNode;
            }   
            dummy->next = current;
        }
        
        return dummy->next;
    }
};
