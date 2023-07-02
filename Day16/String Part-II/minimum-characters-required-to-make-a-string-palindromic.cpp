// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

int Solution::solve(string A) {
    string s=A;
    reverse(A.begin(),A.end());
    s=s+'#'+A;
    int n =s.size();
    vector<int>pi(n,0);
    for(int i =1;i<n;i++){
        int j =pi[i-1];
        while(j>0&&s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return A.size()-pi[n-1];
}
