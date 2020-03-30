class Solution {
public:
    
    int getSum(int a, int b) {
        bitset<32> bitA(a);
        bitset<32> bitB(b);

        while (bitB.any()){
            bitset<32> carry = bitA & bitB;
            bitA = bitA ^ bitB;
            bitB = carry << 1;
        }

        return (int)bitA.to_ulong();
    }   
};
