class Solution {
public:
    string getSorted(string a){
        sort(a.begin(), a.end());
        return a;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        if (!strs.empty()){
            unordered_map<string, vector<string>> groups;
            
            for (int i=0; i<strs.size(); ++i){
                string key = getSorted(strs[i]);
                
                if (groups.count(key)){
                    groups[key].push_back(strs[i]);
                }
                else{
                    vector<string> newGroup(1, strs[i]);
                    groups.insert(pair<string, vector<string>>(key, newGroup));
                }
            }
            
            for (auto it = groups.begin(); it != groups.end(); ++it){
                res.push_back(it->second);
            }
        }
        
        
        return res;
    }
};
