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

/**
Basically start from the head. Then go to he next 
**/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        if (head->next == nullptr) {
            return head;
        }

        auto prev = head; // Guaranteed that this is not null
        auto curr = head->next; // Guaranteed that this is not null
        head->next = nullptr;

        while (curr != nullptr) {
            // Save the next one in the list 
            // and set the next pointer to the previous
            auto next = curr->next;
            curr->next = prev;

            // move prev forward, then move curr forward
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
