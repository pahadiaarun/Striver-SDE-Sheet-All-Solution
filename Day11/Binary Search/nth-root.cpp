// https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double low = 1;
    double high = m;
    double eps = 1e-7; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    return low;
}
