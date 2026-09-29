class MinStack {
public:
    stack<int> st;
    stack<int> min;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(min.empty()){
            min.push(val);
        } else {
            int top = min.top();
            if (val < top){
                min.push(val);
            } else {
                min.push(top);
            }
        }

    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};


//12,2,15,11,3,5,1
//12,2,2,2,
