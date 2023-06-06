// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        vector<vector<int>>res;
        for(auto itv:intervals){
            if(itv[1]<=end) continue;
            else{
                if(itv[0]<=end){
                    end=itv[1];
                }
                else{
                    res.push_back({start,end});
                    start=itv[0];
                    end=itv[1];
                }
            }
        }
        res.push_back({start,end});
        return res;
    }
};
