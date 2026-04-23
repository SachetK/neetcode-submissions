/**
There is a mathematical identity where sum of a set of numbers in a range, 
inclusive, is equal to n*(n+1)/2.

No overflow issues because length <= 1000.
**/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto len = nums.size();
        auto sum = len*(len+1) / 2;

        for (auto num : nums) {
            sum -= num;
        }
        
        return sum;
    }
};
