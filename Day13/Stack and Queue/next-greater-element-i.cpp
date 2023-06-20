// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        vector<int>res;
        int n=nums2.size();
           
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.size()==0) mp[nums2[i]]=-1;
            else mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++){
            res.push_back(mp[nums1[i]]);
        }
        
        return res;
    }
};

