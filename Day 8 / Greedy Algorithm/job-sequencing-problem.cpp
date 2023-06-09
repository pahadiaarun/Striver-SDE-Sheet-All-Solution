// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i].profit,arr[i].dead});
        }
        sort(v.rbegin(),v.rend());
        vector<int>t(n+1,-1);
        int res=0,k=0;
        for(auto i:v){
            if(t[i.second]==-1){
                t[i.second]=1;
                res+=i.first;
                k++;
            }
            else{
                for(int j=i.second-1;j>0;j--){
                    if(t[j]==-1){
                        t[j]=1;
                        res+=i.first;
                        k++;
                        break;
                    }
                }
            }
        }
        return {k,res};
    }

