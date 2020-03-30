class Solution {
public:
    
string longestPalindrome(string s) {
    vector<vector<bool>> isPalirome(s.size()+2, vector<bool>(s.size()+2));
    int index = 0;
    int length = 1;

    for (int right=0; right<s.size(); ++right){
        isPalirome[right][right] = true;

        for (int left=right-1; left>=0; --left){
            if (s[left] == s[right]){
                isPalirome[left][right] = (left + 1 == right) ? true: isPalirome[left+1][right-1];
            }

            if (isPalirome[left][right] && right - left + 1 > length){
                index = left;
                length = right - left + 1;
            }
        }
    }

    //cout<<"(left, right) "<<left<<" "<<right<<endl;
    return s.substr(index, length);
}
};
