// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        unordered_set<char>st;
        int res=INT_MIN,n=s.size();
        int l=0;
        for(int i=0;i<n;i++){
            if(st.count(s[i])){
                while(l<i && st.count(s[i])) st.erase(s[l++]);
            }
            st.insert(s[i]);
            res=max(res,i-l+1);
        }
        return res;
    }
};
