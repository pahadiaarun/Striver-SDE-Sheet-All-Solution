// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
int longestIncreasingSubsequence(int nums[], int n)
{
    // Write Your Code here
    vector<int>ans;
        int length=1;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
                length++;
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return length;
}

