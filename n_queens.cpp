class Solution {
public:
    bool finished(vector<string>& board, int n)
    {
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'Q'){
                    count++;
                }
            }
        }
    return count == n;
    }
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
       for(int i = 0; i < n; i++){
            if(board[row][i] == 'Q' || board[i][col] == 'Q'){
                return false;
            }
        }
        
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] =='Q'){
                return false;
            }
        }
        
        for(int i = row, j = col; i >=0 && j < n; i--, j++){
            if(board[i][j] =='Q'){
                return false;
            }            
        }
        return true;
    }
    void backtrack(vector<vector<string>> &res, vector<string> &board, int row, int n)
    {
        if(finished(board,n))
        {
            // cout<<"hello";
            // for(int i=0;i<n;i++)
            // {
            //     for(int j=0;j<n;j++)
            //         cout<<res[i][j]; 
            //         cout<<endl;
            // }
            res.push_back(board);
        }
        else
        {
            for(int j=0; j<n; j++)
            {
                if(isSafe(board,row,j,n))
                {
                    board[row][j] = 'Q';
                    backtrack(res,board,row+1,n);                      
                    board[row][j] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
               
        vector<vector<string>> res;
        string line = "";
        for(int i = 0; i < n; i++){
            line+='.';
        }
        vector<string> board(n,line);
        backtrack(res,board,0,n);
        return res;
    }
};