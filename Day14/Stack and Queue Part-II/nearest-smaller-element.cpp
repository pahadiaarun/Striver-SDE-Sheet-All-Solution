// https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int>res(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=A[i]) st.pop();
        if(!st.empty()) res[i]=st.top();
        st.push(A[i]);
    }
    return res;
}

