class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sixteen = 0x0000FFFF;
        uint32_t eight = 0x00FF00FF;
        uint32_t four = 0x0F0F0F0F;
        uint32_t two = 0x33333333;
        uint32_t one = 0x55555555;

        uint32_t left = 0;
        uint32_t right = 0;
        
        right = n & sixteen;
        left = n & (sixteen << 16);
        n = (right << 16) | (left >> 16);

        right = n & eight;
        left = n & (eight << 8);
        n = (right << 8) | (left >> 8);

        right = n & four;
        left = n & (four << 4);
        n = (right << 4) | (left >> 4);

        right = n & two;
        left = n & (two << 2);
        n = (right << 2) | (left >> 2);

        right = n & one;
        left = n & (one << 1);
        n = (right << 1) | (left >> 1);

        return n;
    }
};
