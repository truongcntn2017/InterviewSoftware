class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {        
        if (m > 0 || n > 0){
            vector<int> res;
            int index1 = 0;
            int index2 = 0;
        
            while (index1 < m || index2<n){
                if ((index2 >= n) ||(index1 < m && nums1[index1] <= nums2[index2])){
                    res.push_back(nums1[index1++]);
                }
                else{
                    res.push_back(nums2[index2++]);
                }
            }   
            
            nums1 = res;
        }
    }
};
