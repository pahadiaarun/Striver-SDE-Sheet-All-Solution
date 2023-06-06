// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n=arr.size();
        int fast=arr[0];
        int slow=arr[0];
        do{
            fast=arr[arr[fast]];
            slow=arr[slow];
        }while(fast!=slow);
        fast=arr[0];
        while(fast!=slow){
            fast=arr[fast];
            slow=arr[slow];
        }
        return slow;
    }
};
