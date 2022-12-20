class MinStack {
public:
    stack<int> stk, mnstk;
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        stk.push(val);
        if(mnstk.empty() || val <= mnstk.top())
            mnstk.push(val);
    }
    
    void pop() 
    {
        int x = stk.top();
        if(x == mnstk.top())
            mnstk.pop();
        stk.pop();
    }
    
    int top() 
    {
        return stk.top();
    }
    
    int getMin() 
    {
        return mnstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */