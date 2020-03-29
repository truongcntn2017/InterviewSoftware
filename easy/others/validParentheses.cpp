class Solution {
public:
    bool isBacket(char a, char b){
        return (a == '(' && b == ')' ) || (a == '[' && b == ']' ) || (a == '{' && b == '}' ); 
    }
    
    bool isValid(string s) {
        bool res = true;
        
        if (!s.empty()){
            stack<char> expression;
            expression.push(s[0]);
            
            for (int i=1; i<s.size();++i){
                if (!expression.empty() && isBacket(expression.top(), s[i])){
                    expression.pop();
                }
                else{
                    expression.push(s[i]);
                }
            }
            
            res = expression.empty();
        }
            
        return res;
    }
};
