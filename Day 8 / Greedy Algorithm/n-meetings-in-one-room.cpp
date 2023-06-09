// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int res=1;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int e=v[0].first;
        for(int i=0;i<n;i++){
            if(e<v[i].second){
                e=v[i].first;
                res++;
            }
        }
        return res;
    }
};

