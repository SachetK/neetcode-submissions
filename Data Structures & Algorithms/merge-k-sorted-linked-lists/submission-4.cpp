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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<pair<int, ListNode*>, std::vector<pair<int, ListNode*>>,
                            std::greater<pair<int, ListNode*>>>
            topNodes;

        for (const auto& head : lists) {
            if (head == nullptr) {
                continue;
            }

            topNodes.push({head->val, head});
        }

        if (lists.size() == 0) {
            return nullptr;
        }

        ListNode* dummy = new ListNode();
        auto head = dummy;

        while (!topNodes.empty()) {
            head->next = topNodes.top().second;
            topNodes.pop();
            head = head->next;


            if (head->next != nullptr) {
                topNodes.push({head->next->val, head->next});
            }

        }

        return dummy->next;
    }
};
