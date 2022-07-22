/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *small = new ListNode(0);
        ListNode *big = new ListNode(0);
        
        ListNode *s = small, *b = big;
        
        while(head){
            
            if(head -> val < x){
                s -> next = head;
                s = s -> next;
            }
            
            else{
                b -> next = head;
                b = b -> next;
            }
            
            head = head -> next;
        }
        
        s -> next = big -> next;
        b -> next = nullptr;
        
        return small -> next;
    }
};