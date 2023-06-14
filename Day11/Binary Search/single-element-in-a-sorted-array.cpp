// https://leetcode.com/problems/single-element-in-a-sorted-array/

int singleNonDuplicate(vector<int>& nums)
{
  // Write your code here
    int l=0,h=nums.size()-2;
        while(l<=h){
            int mid=(l+h)>>1;
            if(nums[mid]==nums[mid^1]) l=mid+1;
      else h=mid-1;

        }
        return nums[l];
}

