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
private:

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (left != nullptr && right != nullptr) {

            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            }
            else {
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        if (left != nullptr) {
            curr->next = left;
        }
        else {
            curr->next = right;
        }

        return dummy->next;
    }

public:

    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split
        ListNode* right = slow->next;
        slow->next = nullptr;

        // Sort left half
        ListNode* left = sortList(head);

        // Sort right half
        right = sortList(right);

        // Merge
        return merge(left, right);
    }
};