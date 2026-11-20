class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string c: tokens){
            if((c == "+") || (c == "-") || (c == "*") || (c == "/")){
                int num2 = stoi(st.top());
                st.pop();

                int num1 = stoi(st.top());
                st.pop();

                if (c == "+") {
                    st.push(to_string(num1+num2));
                } else if(c == "-"){
                    st.push(to_string(num1-num2));
                } else if(c == "*"){
                    st.push(to_string(num1*num2));
                } else {
                    st.push(to_string(num1/num2));
                }
            } else {
                st.push(c);
            }
        }
        int result = stoi(st.top());
        st.pop();
        return result;
    }
};
