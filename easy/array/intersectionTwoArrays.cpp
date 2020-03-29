class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        if (!nums1.empty() && !nums2.empty()){
            int index1 = 0;
            int index2 = 0;
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
        
            while (index1 < nums1.size() && index2<nums2.size()){
                if (nums1[index1] > nums2[index2]){
                    ++index2;
                }
                else if(nums1[index1] < nums2[index2]){
                    ++index1;
                }
                else{
                    result.push_back(nums1[index1]);
                    ++index1;
                    ++index2;
                }
            }
        }
        
        return result;
    }
};
