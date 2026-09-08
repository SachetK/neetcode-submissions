class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int remaining = 0;
        for (int num : nums) {
            remaining ^= num;
        }
        return remaining;
    }
};
