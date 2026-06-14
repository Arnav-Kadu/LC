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
    int pairSum(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // slow is till the half way
        // reverse it there onwards
        ListNode* prev=NULL;
        while(slow){
            ListNode* next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        int mx=INT_MIN;
        while(prev){
           mx=max(prev->val+head->val,mx);
           head=head->next;
           prev=prev->next;
        }
        return mx;
    }
};