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
    int getDecimalValue(ListNode* head) {
        string s;
        while(head!=NULL){
            s+=to_string(head->val);
            head=head->next;
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        int ans=0;
        int multi=1;
        for(auto i:s){
            ans+=(i-'0')*multi;
            multi*=2;
        }
        return ans;
    }
};