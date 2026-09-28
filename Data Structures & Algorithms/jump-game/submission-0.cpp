class Solution {
public:
    bool canJump(vector<int>& nums) {
        int toReach = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= toReach) {
                toReach = i;
            }
        }

        return toReach == 0;
    }
};
