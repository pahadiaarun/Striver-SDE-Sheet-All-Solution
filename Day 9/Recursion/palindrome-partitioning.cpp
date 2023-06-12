// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        solve(s,res,0,vector<string>());
        return res;
    }
    void solve(string s, vector<vector<string>>&res, int i, vector<string>temp){
        if(i==s.size()){
            res.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            string x=s.substr(i,j-i+1);
            if(isValid(x)){
                temp.push_back(x);
                solve(s,res,j+1,temp);
                temp.pop_back();
            }
        }
    }
    bool isValid(string s){
        int l=0,h=s.size()-1;
        while(l<=h) if(s[l++]!=s[h--]) return 0;
        return 1;
    }
};

