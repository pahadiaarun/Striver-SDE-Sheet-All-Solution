// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<pair<int,int>>st;
        int res=0;
        vector<int>v1(n,n);
        vector<int>v2(n,-1);
        for(int i=0;i<n;i++){
            while(st.size() && st.top().first>=heights[i]) st.pop();
            if(st.size()) v2[i]=st.top().second;
            st.push({heights[i],i});
        }
        st = stack<pair<int,int>>();
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top().first>=heights[i]) st.pop();
            if(st.size()) v1[i]=st.top().second;
            st.push({heights[i],i});
        }
        for(int i=0;i<n;i++){
            res=max(res,heights[i]*(v1[i]-v2[i]-1));
        }
        return res;
    }
};

