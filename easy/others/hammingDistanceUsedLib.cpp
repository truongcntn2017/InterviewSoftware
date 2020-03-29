class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> digits(x^y);
        
        return digits.count();
    }
};
