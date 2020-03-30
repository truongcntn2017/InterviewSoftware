
class Solution {
public:
    unordered_map<char, vector<string>> buttons;
    void makeDigitToCh(){
        vector<string> temp2(3);
        temp2 = {"a", "b", "c"};
        vector<string> temp3(3);
        temp3 = {"d", "e", "f"};
        vector<string> temp4(3);
        temp4 = {"g", "h", "i"};
        vector<string> temp5(3);
        temp5 = {"j", "k", "l"};
        vector<string> temp6(3);
        temp6 = {"m", "n", "o"};
        vector<string> temp7(4);
        temp7 = {"p", "q", "r", "s"};
        vector<string> temp8(3);
        temp8 = {"t", "u", "v"};
        vector<string> temp9(4);
        temp9 = {"w", "x", "y", "z"};

        buttons.insert(pair<char, vector<string>>('2', temp2));
        buttons.insert(pair<char, vector<string>>('3', temp3));
        buttons.insert(pair<char, vector<string>>('4', temp4));
        buttons.insert(pair<char, vector<string>>('5', temp5));
        buttons.insert(pair<char, vector<string>>('6', temp6));
        buttons.insert(pair<char, vector<string>>('7', temp7));
        buttons.insert(pair<char, vector<string>>('8', temp8));
        buttons.insert(pair<char, vector<string>>('9', temp9));
    }
    
    void letterCombinationsHelper(vector<string>& res, string digits, string temp, int index) {
        
        if (index < digits.size()){
            for (int i=0; i< buttons[digits[index]].size();++i){
                string next = buttons[digits[index]][i];
                letterCombinationsHelper(res, digits, temp + next, index+1);
            }
        }
        else{
            res.push_back(temp);
        }
    }
    vector<string> letterCombinations(string digits) {
        makeDigitToCh();
        vector<string> res;
        
        if (!digits.empty()){
            letterCombinationsHelper(res, digits,"", 0);
        }
        
        return res;
    }
};

