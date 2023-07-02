// https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int>res;
    unordered_map<int,int>mp;
    int i=0,j=0;
    while(i<A.size()){
        if(i-j==B){
            res.push_back(mp.size());
            mp[A[j]]--;
            if(mp[A[j]]==0) mp.erase(A[j]);
            j++;
        }
        mp[A[i]]++;
        i++;
    }
    res.push_back(mp.size());
    return res;
}

