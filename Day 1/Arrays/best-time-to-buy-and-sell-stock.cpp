// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=0,p=prices[0];
        for(auto i:prices){
            p=min(p,i);
            mx=max(mx,i-p);
        }
        return mx;
    }
};
