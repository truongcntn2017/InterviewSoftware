class Solution {
public:
    double myPow(double x, int n) {
        bool negative = (n < 0);
        double res = 1;
        n = abs(n);
        
        while (n > 0){
            if (n & 1){
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        
        return (negative)? 1/ res: res;
    }
};
