/*
o(1), o(1)

good solution is to use 2 stacks

optimized solution is to use 1 stack and a variable to keep track of the min value
When pushing a new value that is less than or equal to the current min, we first push the current min onto the stack, then update the min to the new value, and finally push the new value.
When popping, if the popped value is equal to the current min, we pop again to retrieve the previous min value.

should learn the optimized solution later
*/

    vector<int> st, min;
    int h = 0;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        if(h == 0)
            min.push_back(val);
        else{
            if(val < min[h-1]){
                min.push_back(val);
            }else{
                min.push_back(min[h-1]);
            }
        }
        ++h;
    }
    
    void pop() {
        st.pop_back();
        min.pop_back();
        --h;
    }
    
    int top() {
        cout << h << endl;
        return st[h-1]; 
    }
    
    int getMin() {
        return min[h-1];
    }


class MinStack {
    stack<long long> s; long long minEle;
public:
    void push(int val) {
        if (s.empty()) { s.push(val); minEle = val; }
        else if (val < minEle) { s.push(2LL*val - minEle); minEle = val; }
        else s.push(val);
    }
    void pop() {
        long long t = s.top(); s.pop();
        if (t < minEle) minEle = 2*minEle - t;
    }
    int top() { return s.top() < minEle ? (int)minEle : (int)s.top(); }
    int getMin() { return (int)minEle; }
};