class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        
        if (!s.empty()){
            unordered_map<char, int> index;
            int lastDuplicate = -1;
            
            for (int i=0; i<s.size();++i){
                if (index.count(s[i])){
                    lastDuplicate = max(lastDuplicate, index[s[i]]);
                    index[s[i]] = i;
                }
                else{
                    index.insert(pair<char, int>(s[i], i));
                }
                
                res = max(res, i - lastDuplicate);
            }
        }
        
        return res;
    }
};
