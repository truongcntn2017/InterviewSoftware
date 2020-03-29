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

    bool isPalindrome(ListNode* head) {
        int length = getLength(head);
        int paliromed = true;
        
        if (length > 1){
            int n = length - length/2;
            ListNode* current = head;
        
            current = moveNth(current, n); // Count number from 0
            current = reverseList(current);
            
            while (head && current){
                if (head->val != current->val){
                    paliromed = false;
                    break;
                }
                
                head = head->next;
                current = current->next;
            }
        }
        
        return paliromed;
    }
};
