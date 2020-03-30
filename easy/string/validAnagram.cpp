class Solution {
public:
    vector<int> calculateFrequency(string s){
        vector<int> freq('z'-'a'+1, 0);
        
        for (int i=0; i<s.size();++i)
            freq[s[i] - 'a']++;
        
        return freq;
    }
    bool isEqual(vector<int> a, vector<int> b){
        bool equal = (a.size() == b.size());
        
	    if (equal){
            for (int i=0; i<a.size();++i){
            	if (a[i] != b[i]){
                   equal = false;
                   break;
                }
           }
	    }
        
        return equal;
    }
    bool isAnagram(string s, string t) {
        return isEqual(calculateFrequency(s), calculateFrequency(t));
    }
};
