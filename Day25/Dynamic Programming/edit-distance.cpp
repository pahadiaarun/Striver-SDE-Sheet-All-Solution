// https://leetcode.com/problems/edit-distance/

int editDistance(string s, string t)
{
    //write you code here
    int n=s.size(),m=t.size();
        vector<int>prev(m+1);
        vector<int>curr(m+1);
        for(int i=0;i<=m;i++) prev[i] = i;

        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j] = prev[j-1];
                else{
                    int in=prev[j-1];
                    int dl=prev[j];
                    int rp=curr[j-1];
                    curr[j] = 1+min(in,min(dl,rp));
                }
            }
            prev= curr;
        }
        return prev[m];
}

