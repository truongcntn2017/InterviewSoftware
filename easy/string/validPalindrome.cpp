class Solution {
public:    
bool isAlphanumeric(char ch){ 'A' -> 'a'
    ch = tolower(ch);
    return ('a' <= ch && ch<='z') || ('0' <=ch && ch <='9');
}
    
void preprocessingString(string &s){
    int count = 0;

    for (int i=0; i<s.size(); ++i)
        if (isAlphanumeric(s[i])){
            s[count++] = tolower(s[i]);
        }

    s.resize(count);        
}
bool isPalindrome(string s) {
    bool  flag = true;
    // considering only alphanumeric characters and ignoring cases
    preprocessingString(s);

    for (int i=0; i<s.size()/2;++i)
        if (s[i] != s[s.size()-1-i]){
            flag = false;
        }

    return flag;
}

};
