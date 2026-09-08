class KthLargest {
   public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int limit;

    KthLargest(int k, vector<int>& nums) : limit(k), pq(nums.begin(), nums.end()) {
        while (pq.size() > k) {
            pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > limit) {
            pq.pop();
        }
        
        return pq.top();
    }
};
