#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.empty()){
            int lastUniqueIndex = 0;
            
            for (int cur = 1; cur<nums.size(); ++cur){
                if (nums[lastUniqueIndex] != nums[cur]){
                    nums[++lastUniqueIndex] = nums[cur]; 
                }
            }
            
            nums.resize(lastUniqueIndex+1);
        }
        return nums.size();
    }
};

int main(){
    return 0;
}

