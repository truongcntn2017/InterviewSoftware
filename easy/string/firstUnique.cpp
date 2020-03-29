class Solution {
public:
    bool isUniqueCharacter( char ch, vector<int> freq){
        return freq[ch - 'a'] == 1;
    }
    vector<int> calculateFrequency(string s){
        vector<int> freq('z'-'a'+1, 0);
        
        for (int i=0; i<s.size();++i)
            freq[s[i] - 'a']++;
        
        return freq;
    }
    
    int firstUniqChar(string s) {
        int index = -1;
        vector<int> freq = calculateFrequency(s);
        
        for (int i=0; i<s.size();++i)
            if (isUniqueCharacter(s[i], freq)){ 
                index = i;
                break;
            }
        
        return index;
    }
};
