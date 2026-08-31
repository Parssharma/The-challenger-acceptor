/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    Node* clone(Node*&head, Node*&tail, int d) {
        Node* newnode = new Node(d);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
            return head;
        } else {
            tail->next = newnode;
            tail = tail->next;
        }
        return head;
    }

public:
    Node* copyRandomList(Node* head) {
        Node* headClone = nullptr;
        Node* tailClone = nullptr;
        Node* temp = head;
        while (temp != nullptr) {
            clone(headClone, tailClone, temp->val);
            temp = temp->next;
        }

        unordered_map<Node*, Node*> OldtoNew;
        Node* oldNode = head;
        Node* newNode = headClone;
        while (oldNode != NULL) {
            OldtoNew[oldNode] = newNode;
            oldNode = oldNode->next;
            newNode = newNode->next;
        }

        oldNode = head;
        newNode = headClone;
        while (oldNode != nullptr) {
            newNode->random = OldtoNew[oldNode->random];
            newNode = newNode->next;
            oldNode = oldNode->next;
        }
        return headClone;
    }
};