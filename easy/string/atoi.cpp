class Solution {
public:
bool isDigit(char s){
    return ('0' <= s && s <= '9');
}
    
int myAtoi(string str) {
    long long res = 0;
    int sign_factor = 1;
    bool start_parse = false;
    
    for (int i=0; i<str.size();++i){
        if (str[i] == ' ' and not start_parse){
            continue;
        }
        else if (isDigit(str[i])){
            start_parse = true;
            res = res*10 + (str[i]-'0');
            res = min(res, (long long)pow(2, 31));
        }
        else if((str[i] == '+' || str[i] == '-') && !start_parse){
            start_parse = true;
            sign_factor = (str[i] == '+') ? 1 : -1;
        }
        else{
            break;
        }
    }
    
    return (sign_factor == 1) ? min(res, (long long)INT_MAX): max(res*sign_factor, (long long)INT_MIN);
}


};
