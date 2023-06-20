// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="",temp=strs[0];
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<strs.size();j++){
                if(temp[i]!=strs[j][i]) return s;
            }
            s+=temp[i];
        }
        return s;
    }
};

