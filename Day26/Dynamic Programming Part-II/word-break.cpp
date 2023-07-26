// https://leetcode.com/problems/word-break/

#include <bits/stdc++.h> 
bool wordBreak(string s, unordered_set<string> &set, vector<int> &memo, int start){
        if(start == s.size()){
            return true;
        }
        if(memo[start] != -1){
            return memo[start];
        }
        for(int i=start; i<s.size(); i++){
            if(set.count(s.substr(start, i+1-start)) && wordBreak(s, set, memo, i+1)){
                memo[start] = true;
                return true;
            }
        }
        return memo[start] = false;
    }
bool wordBreak(vector < string > & arr, int n, string & s) {
    // Write your code here.
    vector<int> memo(s.size(), -1);
        unordered_set<string> set(arr.begin(), arr.end());
        return wordBreak(s, set, memo, 0);
}

