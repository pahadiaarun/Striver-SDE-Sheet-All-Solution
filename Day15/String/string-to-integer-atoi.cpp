// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int n=s.size(),ans=0,i=0;
        string res="";
        
        while(i<n && s[i]==' ') i++;
        
        if(i<n && (s[i]=='+' || s[i]=='-')) res+=s[i++];
        
        while(i<n && s[i]>='0' && s[i]<='9') res+=s[i++];
        
        int limit=INT_MAX/10;
        
        int sign= (res[0]=='-') ? -1 : 1; 
        
        for(int i=(res[0]=='-' || res[0]=='+') ? 1 : 0;i<res.size();i++){
            int digit = res[i] - '0';
            if(ans>limit || (ans==limit && digit>7)){
                return (sign==-1) ? INT_MIN : INT_MAX;
            }
            ans=ans*10+digit;
        }
        
        return ans*sign;
    }
};

