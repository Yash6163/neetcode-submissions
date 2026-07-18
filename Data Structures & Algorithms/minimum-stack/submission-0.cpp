class MinStack {
public:
    vector<int>st;
    MinStack() {
        st={};
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        int minval=INT_MAX;
        for(auto it : st)minval=min(minval,it);
        return minval;
    }
};
