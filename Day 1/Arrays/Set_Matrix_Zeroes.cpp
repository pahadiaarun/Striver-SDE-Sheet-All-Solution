// https://leetcode.com/problems/set-matrix-zeroes/

void setZeroes(vector<vector<int>>& matrix) {
        int col=1;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0) col=0;
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=n-1;i>0;i--){
            for(int j=m-1;j>0;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0) for(int j=0;j<m;j++) matrix[0][j]=0;
        if(col==0) for(int i=0;i<n;i++) matrix[i][0]=0;
}
