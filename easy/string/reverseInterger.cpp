class Solution {
public:
    long long reverseHelper(long long n, long long sign){
        long long res = 0;
        n = abs(n);
        
        while (n>0){
            res *= 10;
            res += n % 10; // digits
            n /= 10;
        }
        
        return res*sign;
    }
    int reverse(int x) {
        int sign = (x < 0)? -1: 1;
        long long n = x;
        long long res = reverseHelper(n, sign);
        
        return (INT_MIN <= res && res <= INT_MAX) ? res: 0;
    }
};
