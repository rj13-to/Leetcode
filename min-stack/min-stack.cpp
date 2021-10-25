class MinStack {
public:
    stack<int>st;
    multiset<int>se;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        se.insert(val);
    }
    
    void pop() {
        se.erase(se.lower_bound(st.top()));
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *se.begin();
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