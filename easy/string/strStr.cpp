class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = -1;
        
        if (haystack.empty() && needle.empty()){
            res = 0;
        }
        else if (haystack.size() >= needle.size()){
            
            for (int i=0; i<haystack.size()-needle.size()+1; ++i){
                if (haystack.substr(i, needle.size()) == needle){
                    res = i;
                    break;
                }
            }
        }
        
        return res;
    }
};
