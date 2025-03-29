class MinStack {
public:
    stack<int> st;
    int minE=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minE>val) minE=val;
    }
    
    void pop() {
        st.pop();
        stack<int> temp;
        minE=INT_MAX;
        while(st.size()){
            temp.push(st.top());
            minE=min(minE,st.top());
            st.pop();
        }
        while(temp.size()){
            st.push(temp.top());
            temp.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minE;
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