
class Solution {
public:
    void generateParenthesisHelper(vector<string>& res, string temp, int num1, int num2, int n){
        if (temp.size() == 2*n){
            res.push_back(temp);
        }
        else{
            if (num1 < n){
                generateParenthesisHelper(res, temp + "(", num1+1, num2, n);
            }
            if (num2 < num1){
                generateParenthesisHelper(res, temp + ")", num1, num2+1, n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisHelper(res, "", 0, 0, n);
        return res;
    }
};

