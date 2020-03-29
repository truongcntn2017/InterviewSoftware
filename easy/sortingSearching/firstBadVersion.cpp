// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        int res;
        
        
        while (left <= right){
            mid = left  + (right-left) / 2;
            // mid = (left + right)/ 2;
            if (isBadVersion(mid)){
                res = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return res;
    }
};
