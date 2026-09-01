class Solution {
public:
    Node* flatten(Node* head) {

        if (head == nullptr) {
            return head;
        }

        Node* curr = head;

        while (curr != nullptr) {

            if (curr->child != nullptr) {

                // Save the original next node
                Node* next = curr->next;

                // Flatten the child list
                Node* child = flatten(curr->child);

                // Connect curr -> child
                curr->next = child;
                child->prev = curr;

                // Find the last node of the child list
                Node* tail = child;

                while (tail->next != nullptr) {
                    tail = tail->next;
                }

                // Connect child list -> original next
                tail->next = next;

                if (next != nullptr) {
                    next->prev = tail;
                }

                // Remove child pointer
                curr->child = nullptr;
            }

            curr = curr->next;
        }

        return head;
    }
};