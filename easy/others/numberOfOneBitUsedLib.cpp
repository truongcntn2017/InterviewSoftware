class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> digits(n);
        
        return digits.count();
    }
};
