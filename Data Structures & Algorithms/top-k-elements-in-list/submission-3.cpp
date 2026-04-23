class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freqs;

        for (auto num : nums) {
            if (freqs.count(num) > 0) {
                freqs[num]++;
            } else {
                freqs[num] = 1;
            }
        }

        std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> heap;
        for (const auto& entry : freqs) {
            heap.push({ entry.second, entry.first }); // we sort by frequencies then
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> ans;
        while (!heap.empty()) {
            auto entry = heap.top().second;
            heap.pop();

            ans.push_back(entry);
        }

        return ans;
    }
};
