// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        for(auto i:nums) mp[i]++;
        for(auto i:mp){
            if(pq.size()<k){
                pq.push({i.second,i.first});
            }
            else if(pq.size()==k){
                auto p=pq.top();
                if(p.first<i.second){
                    pq.pop();
                    pq.push({i.second,i.first});
                }
            }
        }
        vector<int>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

