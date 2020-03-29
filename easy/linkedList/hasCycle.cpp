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
    bool hasCycle(ListNode *head) {
        ListNode* turtle = head;
        ListNode* rabbit = head;
        bool isCycle = false;
        
        while (turtle && rabbit){
            
            turtle = turtle->next; 
            rabbit = (rabbit->next) ? rabbit->next->next : NULL;
            
            if (turtle == rabbit && rabbit != NULL){
                isCycle = true;
                break;
            }
        }
        
        return isCycle;
    }
};
