// https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>res;
    for(auto i:q){
        if(i[0]==0) pq.push(i[1]);
        else{
            res.push_back(pq.top());
            pq.pop();
        }
    }
    return res;
}

