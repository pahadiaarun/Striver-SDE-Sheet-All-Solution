// https://leetcode.com/problems/reverse-pairs/

class Solution {
public:
    int merge(vector<int>& nums, int l, int m, int h, vector<int>& temp) {
        int i = l, j = m, k = l, cnt = 0;
        while (i < m && j <= h) {
            if (nums[i] <= 2LL * nums[j]) i++;
            else {
                cnt += (m - i);
                j++;
            }
        }
        i = l, j = m, k = l;
        while (i < m && j <= h) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i < m) {
            temp[k++] = nums[i++];
        }
        while (j <= h) {
            temp[k++] = nums[j++];
        }
        for (int i = l; i <= h; i++) {
            nums[i] = temp[i];
        }
        return cnt;
    }

    int count(vector<int>& nums, int l, int h, vector<int>& temp) {
        int cnt = 0;
        if (l < h) {
            int m = (l + h) / 2;
            cnt += count(nums, l, m, temp);
            cnt += count(nums, m + 1, h, temp);
            cnt += merge(nums, l, m + 1, h, temp);
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return count(nums, 0, nums.size() - 1, temp);
    }
};

