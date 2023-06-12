// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void solve(vector<int>&c, vector<vector<int>>&res, int t, int i, vector<int>&temp){
        if(t==0){
            res.push_back(temp);
            return;
        }
        for(int in=i;in<c.size();in++){
            if(i!=in && c[in]==c[in-1]) continue;
            if(c[in]>t) break;
            temp.push_back(c[in]);
            solve(c,res,t-c[in],in+1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int> temp;
        solve(candidates,res,target,0,temp);
        return res;
    }
};

