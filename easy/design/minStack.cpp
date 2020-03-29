class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> myStack;
    stack<int> minStack;
    
    MinStack() {
    }
    void push(int x) {
        if (myStack.size()){
            minStack.push(min(x, minStack.top()));
            myStack.push(x);
        }
        else{
            myStack.push(x);
            minStack.push(x);
        }
    }
    
    void pop() {
        myStack.pop();
        minStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
