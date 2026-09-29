class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <string> result;
        for(string s: tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int num2 = stoi(result.top());
                result.pop();
                int num1 = stoi(result.top());
                result.pop();
                if( s == "+"){
                    result.push(to_string(num1+num2));
                }else if( s == "-"){
                    result.push(to_string(num1-num2));
                }else if( s == "*"){
                    result.push(to_string(num1*num2));
                } else {
                    result.push(to_string(num1/num2));
                }
            } else {
                result.push(s);
            }
        }
        return stoi(result.top());
    }
};
