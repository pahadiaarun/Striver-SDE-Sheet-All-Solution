// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        int sum=0,res=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0) res=i+1;
            if(mp.find(sum)==mp.end()) mp[sum]=i;
            if(mp.find(sum)!=mp.end()) res=max(res,i-mp[sum]);
        }
        return res;
    }
};

/*
        unordered_map<int,int>mp;
        int sum=0,res=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                res=i+1;
            }
            else{
                if(mp.find(sum)!=mp.end()){
                    res=max(res,i-mp[sum]);
                }
                else mp[sum]=i;
            }
        }
        return res;
*/   
