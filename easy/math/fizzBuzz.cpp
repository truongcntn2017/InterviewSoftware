class Solution {
public:
    
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        
        for (int i=0; i<n;++i){
            string temp;
            if ((i + 1) % 3 == 0)
                temp += "Fizz";
            
            if ((i + 1) % 5 == 0)
                temp += "Buzz";
            
            if ((i+1) % 3 != 0 && (i+1) % 5 != 0)
                temp += to_string(i+1);
            
            result[i] = temp;
        }
        
        return result;
    }
};
