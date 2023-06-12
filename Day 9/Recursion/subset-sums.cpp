// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution
{
public:
    void solve(vector<int> arr, int n, vector<int>& res, int sum){
        if(n<=0){
            res.push_back(sum);
            return;
        }
        solve(arr,n-1,res,sum+arr[n-1]);
        solve(arr,n-1,res,sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>res;
        solve(arr,N,res,0);
        return res;
    }
};
