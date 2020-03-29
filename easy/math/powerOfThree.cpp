class Solution {
public:
    bool isPowerOfThree(int n) {
        bool isPower = false;
        
        if (n > 0){
            
            while (n % 3 == 0){
                n /= 3;    
            }
            
            isPower = (n == 1);
        }
        
        return isPower;
    }
};
