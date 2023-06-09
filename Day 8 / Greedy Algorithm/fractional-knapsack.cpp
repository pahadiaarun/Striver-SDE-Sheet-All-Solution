// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({((double)arr[i].value/(double)arr[i].weight),arr[i].weight});
        }
        sort(v.rbegin(),v.rend());
        double res=0;
        for(int i=0;i<n;i++){
            if(W>=v[i].second){
                res+=((double)v[i].second*v[i].first);
                W=W-v[i].second;
            }
            else{
                res+=((double)W*v[i].first);
                W=0;
                break;
            }
        }
        return res;
    }
        
};

