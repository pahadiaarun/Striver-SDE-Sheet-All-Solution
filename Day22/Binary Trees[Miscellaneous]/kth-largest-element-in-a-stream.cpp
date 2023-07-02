// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int n;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>n) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>n) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

