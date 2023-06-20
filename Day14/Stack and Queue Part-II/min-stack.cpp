// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    long long minEle;
    stack<long long>st;
    
    MinStack() {
        minEle=INT_MAX;
    }
    
    void push(int value) {
        long long val = (long long)value;
        if(st.size()==0){
            st.push(val);
            minEle=val;
            return;
        }
        if(val>=minEle){
            st.push(val);
        }
        else{
            st.push(2*val*1LL-minEle);
            minEle=val;
        }
    }
    
    void pop() {
        if(st.size()==0) return;
        long long x=st.top();
        st.pop();
        if(x<minEle){
            minEle=2*minEle-x;
        }
    }
    
    int top() {
        if(st.size()==0) return -1;
        if(st.top()>=minEle) return st.top();
        return minEle;
    }
    
    int getMin() {
        if(st.size()==0) return -1;
        return minEle;
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

