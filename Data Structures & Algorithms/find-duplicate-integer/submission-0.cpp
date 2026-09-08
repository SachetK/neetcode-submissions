class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while (nums[i] != 0) {
            auto next = nums[i];
            nums[i] = 0;
            i = next;
        }
        return i;
    }
};
