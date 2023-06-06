// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto i:nums) st.insert(i);
        int cnt=0;
        for(auto i:st){
            int ctr=0;
            int x=i;
            if(st.count(x-1)==0){
                while(st.count(x)){
                    x++;
                    ctr++;
                }
            }
            cnt=max(cnt,ctr);
        }
        return cnt;
    }
};

