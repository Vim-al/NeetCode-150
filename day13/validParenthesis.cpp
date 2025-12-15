/*
o(n), o(n)

optimized solution is to use stack
check for edge cases like odd length string and when the stack itself is empty(happens when closing bracket appears before any opening bracket)

*/

    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            if(c==')' || c==']' || c=='}'){
                if(st.empty()) return false;
                if((c==')' and st.top()=='(') || (c==']' and st.top()=='[') || (c=='}' and st.top()=='{'))
                    st.pop();
                else st.push(c);
            }
            else{
                st.push(c);
            }
        }
        if(st.empty())
            return true;
        return false;
    }