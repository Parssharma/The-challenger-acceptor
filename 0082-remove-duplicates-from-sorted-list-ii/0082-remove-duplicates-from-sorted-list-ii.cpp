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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next==nullptr){
            return head;
        }
        ListNode dummy(0);
        dummy.next=head;

        ListNode* temp=&dummy;
        ListNode* curr=head;

        while(curr!=nullptr && curr->next!=nullptr ){
            
            if(curr->val==curr->next->val){
               int val=curr->val;
            while(curr!=nullptr && curr->val==val){
                curr=curr->next;
            }
            temp->next=curr;
            }else{
                temp=curr;
                curr=curr->next;
            }
        }
        return dummy.next;
    }
};