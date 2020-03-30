class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;
        long long mid;
        int res = -1;
        
        while (left <=right){
            mid = left + (right - left)/2;
            if (mid*mid <= x){
                res = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        
        return res;
    }
};
