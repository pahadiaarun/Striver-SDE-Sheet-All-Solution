// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>q;
        int i=0,j=0;
        while(i<nums.size()){
            while(q.size() && q.back()<nums[i]) q.pop_back();
            q.push_back(nums[i]);
            if(i-j+1==k){
                res.push_back(q.front());
                if(q.front()==nums[j]) q.pop_front();
                j++;
            }
            i++;
        }
        return res;
    }
};

