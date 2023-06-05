// https://leetcode.com/problems/next-permutation/

void nextPermutation(vector<int>& nums) {
        int l,k=-1,n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                k=i;
                break;
            }
        }
        if(k==-1) return reverse(nums.begin(),nums.end());
        for(int i=k;i<n;i++){
            if(nums[i]>nums[k]) l=i;
        }
        swap(nums[k],nums[l]);
        reverse(nums.begin()+k+1,nums.end());
    }
