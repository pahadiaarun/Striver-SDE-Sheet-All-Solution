// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue<int>q1;
    
    MyStack() {
    }
    
    void push(int x) {
        if(q1.empty()) q1.push(x);
        else{
            vector<int>v;
            queue<int>q;
            while(q1.size()){
                q.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(q.size()){
                q1.push(q.front());
                q.pop();
            }
            
        }
    }
    
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
