/*
o(n), o(n)

best solution is to use a stack to push all the numbers and when an operator is found pop the last two numbers, apply the operator and push the result back to the stack
and at the end the stack will have only one element which is the result

*/

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int y,x;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                y = st.top();
                st.pop();
                x = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    st.push(x+y);
                }else if(tokens[i] == "-"){
                    st.push(x-y);
                }else if(tokens[i] == "*"){
                    st.push(x*y);
                }else{
                    st.push(x/y);
                }
                
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }