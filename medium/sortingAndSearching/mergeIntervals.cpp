class Solution {
public:
    
// bool myCompare(vector<int> a, vector<int> b){
//     return (a[0] < b[0]);
// }

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    vector<pair<int, int>> seg;
    int indexLast = 0;

    sort(intervals.begin(), intervals.end());

    if (!intervals.empty()){
        res.push_back(intervals[0]);

        for (int i=1; i<intervals.size();++i){
            if (res[indexLast][1] < intervals[i][0]){
                res.push_back(intervals[i]);
                indexLast++;
            }
            else{
                res[indexLast][1] = max(res[indexLast][1], intervals[i][1]);
            }
        }
    }

    return res;
}

};
