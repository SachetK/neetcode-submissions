class Solution {
public:
    int helper(int n, std::unordered_map<int, int>& sols) {
        if (sols.contains(n)) {
            return sols[n];
        }

        sols[n] = helper(n - 1, sols) + helper(n - 2, sols);

        return sols[n];
    }

    int climbStairs(int n) {
        std::unordered_map<int, int> sols;
        sols[1] = 1;
        sols[2] = 2;

        return helper(n, sols);
    }
};
