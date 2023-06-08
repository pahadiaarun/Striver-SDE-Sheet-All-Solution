// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0,o=0;
        for(auto i:nums){
            if(i==1) o++;
            if(i==0){
                res=max(res,o);
                o=0;
            }
        }
        return max(res,o);
    }
};
