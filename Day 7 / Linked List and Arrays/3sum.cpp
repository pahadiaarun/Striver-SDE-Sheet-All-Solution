// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            int target=-(nums[i]);
            while(j<k){
                int x=nums[j]+nums[k];
                if(x>target) k--;
                else if(x<target) j++;
                else{
                    vector<int>v(3,0);
                    v[0]=nums[i];
                    v[1]=nums[j];
                    v[2]=nums[k];
                    res.push_back(v);
                    while(j<k && nums[j]==v[1]) j++;
                    while(j<k && nums[k]==v[2]) k--;
                }
            }
            while(i+1<n && nums[i+1]==nums[i]) ++i;
        }
        return res;
    }
};

