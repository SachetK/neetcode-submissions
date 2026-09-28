class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> heap;
        std::unordered_map<int, int> freq;
        
        for (auto n : nums) {
            freq[n]++;
        }

        for (const auto& [key, value] : freq) {
            heap.push({ value, key });
            if (heap.size() > k) {
                heap.pop();
            }
        }

        std::vector<int> ans;
        while(!heap.empty()) {
            ans.push_back(heap.top().second);
            heap.pop();
        }

        return ans;
    }
};
