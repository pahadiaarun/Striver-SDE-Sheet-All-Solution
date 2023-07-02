// https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1) return s;
        for(int i=2;i<=n;i++){
            string temp="";
            int cnt=1;
            for(int j=1;j<s.size();j++){
                if(s[j]!=s[j-1]){
                    temp+=(to_string(cnt)+s[j-1]);
                    cnt=0;
                }
                cnt++;
            }
            temp+=(to_string(cnt)+s.back());
            s=temp;
        }
        return s;
    }
};
