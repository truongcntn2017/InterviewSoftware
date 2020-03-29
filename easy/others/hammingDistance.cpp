class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x ^ y;
        int sum = 0;
        
        while (temp>0){
            if (temp & 1){
                sum++;
            }
        
            temp = temp >> 1;
        }
        
        return sum;
    }
};
