// https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        int f=1;
        for(int i=1;i<n;i++){
            v.push_back(i);
            f*=i;
        }
        v.push_back(n);
        string s="";
        k--;
        while(1){
            s+=(v[k/f]+'0');
            v.erase(v.begin()+k/f);
            if(v.size()==0) break;
            k=k%f;
            f=f/v.size();
        }
        return s;
    }
};
