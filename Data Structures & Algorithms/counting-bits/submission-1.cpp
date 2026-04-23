class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for (int i = 0; i < n + 1; i++) {
            auto count = 0;
            for (int j = 0; j < 32; j++) {
                count += (i >> j) & 0x1;
            }
            ans.push_back(count);
        }

        return ans;
    }
};
