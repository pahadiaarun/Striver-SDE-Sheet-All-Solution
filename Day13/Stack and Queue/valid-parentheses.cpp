// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto i:s){
            if(st.size()==0) st.push(i);
            else{
                if(i=='(' || i=='{' || i=='[') st.push(i);
                else{
                    if(i==')'){
                        if(st.top()!='(') return 0;
                        else st.pop();
                    }
                    if(i=='}'){
                        if(st.top()!='{') return 0;
                        else st.pop();
                    }
                    if(i==']'){
                        if(st.top()!='[') return 0;
                        else st.pop();
                    }
                }
            }
        }
        return (st.size()==0) ? 1 : 0;
    }
};

