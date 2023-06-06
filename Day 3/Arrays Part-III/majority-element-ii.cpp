// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int e1,e2,c1=0,c2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(c1==0 && nums[i]!=e2){
                e1=nums[i];
                c1=1;
            }
            else if(c2==0 && nums[i]!=e1){
                e2=nums[i];
                c2=1;
            }
            else if(nums[i]==e1) c1++;
            else if(nums[i]==e2) c2++;
            else{
                c1--;c2--;
            }
        }
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==e1) c1++;
            if(nums[i]==e2) c2++;
        }
        vector<int>res;
        if(c1>n/3) res.push_back(e1);
        if(c2>n/3) res.push_back(e2);
        return res;
    }
};

