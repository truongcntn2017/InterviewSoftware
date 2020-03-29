class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";

        if (!strs.empty()){
            res = strs[0];
            bool isModified = false;
            
            for (int i=0; i<strs[0].size();++i){
                if (!isModified){
                    
                    for (int j=1; j<strs.size(); ++j){
                        if (strs[j].size() < i + 1 || strs[j][i] != strs[0][i]){
                            res = strs[0].substr(0, i);
                            isModified = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};
