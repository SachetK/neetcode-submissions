class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;

        while (n != 1) {
            if (seen.count(n)) {
                return false;
            }

            seen.insert(n);
            int temp = 0;

            while (n > 0) {
                int digit = n % 10;
                temp += digit * digit;
                n /= 10;
            }

            n = temp;
        }

        return true;
    }
};
