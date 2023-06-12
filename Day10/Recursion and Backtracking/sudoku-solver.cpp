// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool isP(vector<vector<char>>v,int x,int y,char c){
        for(int i=0;i<9;i++){
            if(v[i][y]==c) return 0;
            if(v[x][i]==c) return 0;
            if(v[3*(x/3)+i/3][3*(y/3)+i%3]==c) return 0;
        }
        return 1;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(isP(board,i,j,k+'0')){
                            board[i][j]=k+'0';
                            if(solve(board)) return 1;
                            else board[i][j]='.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

