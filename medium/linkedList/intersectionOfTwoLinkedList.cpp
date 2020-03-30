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
        ListNode* current = head;
        
        while (current){
            length++;
            current = current->next;
        }
        
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        
        while (lengthA != lengthB){
            if (lengthA > lengthB){
                headA = headA->next;
                lengthA--;
            }
            else{
                headB = headB->next;
                lengthB--;
            }
        }
        
        while (headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};
