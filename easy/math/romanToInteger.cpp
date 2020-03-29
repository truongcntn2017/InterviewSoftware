
class Solution {
public:
    int values['Z' - 'A' + 1] = {0};
   
    void initValues(){
         values['I' - 'A'] = 1;
         values['V' - 'A'] = 5;
         values['X' - 'A'] = 10;
         values['L' - 'A'] = 50;
         values['C' - 'A'] = 100;
         values['D' - 'A'] = 500;
         values['M' - 'A'] = 1000;
    }
    
    int caculateValues(stack<int>& myStack){
        int res = 2*myStack.top();
            
        while (!myStack.empty()){
            res -= myStack.top();
            myStack.pop();
        }
        
        return res;
    }
    
    int romanToInt(string s) {
        int sum = 0;
        
        if (!s.empty()){
            stack<int> myStack;
            // Step 1: init value in values array
            initValues();
            myStack.push(0);
            myStack.push(values[s[0] - 'A']);
            
            for (int i=1; i<s.size();++i){
                if (myStack.top() < values[s[i] - 'A']){
                    myStack.push(values[s[i] - 'A']);
                }
                else{
                    sum += caculateValues(myStack);
                    myStack.push(values[s[i] - 'A']);
                }
            }
            
            sum += caculateValues(myStack);
        }
        
        return sum;
    }
};
