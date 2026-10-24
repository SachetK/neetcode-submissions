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
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        auto copy = &dummy;
        std::unordered_map<Node*, Node*> mapping;

        for (auto i = head; i != nullptr; i = i->next) {
            copy->next = new Node(i->val);
            mapping[i] = copy->next;
            copy = copy->next; 
        }

        for (auto i = head; i != nullptr; i = i->next) {
            auto node = mapping[i];
            if (i->random != nullptr) {
                node->random = mapping[i->random];
            }
        }

        return dummy.next;
    }
};
