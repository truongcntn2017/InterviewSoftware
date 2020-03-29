class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int remain = 1;
        reverse(digits.begin(), digits.end());
        
        for (int i=0; i<digits.size(); ++i){
            digits[i] += remain;
            remain = digits[i] / 10; 
            digits[i] %= 10;
        }
        
        if (remain){ 
            digits.push_back(remain); 
        }
        
        reverse(digits.begin(), digits.end());     
        
        return digits;
    }
};
