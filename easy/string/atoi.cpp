class Solution {
public:
bool isDigit(char s){
    return ('0' <= s && s <= '9');
}
int getInRange(long long a){
    return (a > 0) ? min(a, (long long)(INT_MAX)): max(a, (long long)INT_MIN);
}
    
int myAtoi(string str) {
    long long res = 0;
    int signFactor = 1;
    bool startParse = false;
    
    for (int i=0; i<str.size();++i){
        if (str[i] == ' ' and not startParse){
            continue;
        }
        else if (isDigit(str[i])){
            startParse = true;
            res = res*10 + (str[i]-'0');
            res = min(res, (long long)pow(2, 31));
        }
        else if((str[i] == '+' || str[i] == '-') && !startParse){
            startParse = true;
            signFactor = (str[i] == '+') ? 1 : -1;
        }
        else{
            break;
        }
    }
    
    return getInRange(signFactor*res);
}


};
