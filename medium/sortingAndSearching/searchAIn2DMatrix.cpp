class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res = false;
        
        if (!matrix.empty()){
            for (int i=0; i<matrix.size();++i){
                if (binary_search(matrix[i].begin(), matrix[i].end(), target)){
                    res = true;
                    break;
                }
            }
        }
        
        return res;
    }
};
