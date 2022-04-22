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
    ListNode* mergeNodes(ListNode* head) {
     
        ListNode *ans = new ListNode(0);
        ListNode *itr = ans;
        
        int sum = 0;
        
        for(ListNode *i = head -> next; i ; i = i -> next){
            
            if(i -> val == 0){
                itr -> next = new ListNode(sum);
                itr = itr -> next;
                sum = 0;
            }
            
            else{
                sum += i -> val;
            }
        }
        
        return ans -> next;
    }
};