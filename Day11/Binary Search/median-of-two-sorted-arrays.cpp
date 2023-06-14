// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int l=0,h=n,mid=(n+m+1)/2;
        while(l<=h){
            int x1=(l+h)/2;
            int x2=mid-x1;
            int l1=(x1==0) ? INT_MIN : nums1[x1-1];
            int l2=(x2==0) ? INT_MIN : nums2[x2-1];
            int r1=(x1==n) ? INT_MAX : nums1[x1];
            int r2=(x2==m) ? INT_MAX : nums2[x2];
            if(l1<=r2 && l2<=r1){
                if((m+n)%2) return max(l1,l2);
                else return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) h=x1-1;
            else l=x1+1;
        }
        return 0.0;
    }
};

