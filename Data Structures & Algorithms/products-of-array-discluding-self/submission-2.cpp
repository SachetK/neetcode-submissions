class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size(), 1);
        std::vector<int> suffix(nums.size(), 1);
        std::vector<int> ans(nums.size(), 0);

        for (int i = 1; i < prefix.size(); i++) {
            prefix[i] = prefix[i-1] * nums[i-1]; 
        }

        for (int i = suffix.size() - 2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1]; 
        }

        for (int i = 0; i < ans.size(); i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};
