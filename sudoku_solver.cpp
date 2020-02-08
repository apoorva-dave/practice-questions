class Solution {
public:
    // bool isFinished(vector<vector<char>>& board)
    // {
    //     for(int i=0;i<9;i++)
    //     {
    //         int sum = 0;
    //         for(int j=0;j<9;j++)
    //         {
    //             sum += (board[i][j] - '0');
    //         }
    //         if (sum == 45)
    //             continue;
    //         else
    //             return false;
    //     }
    //     return true;
    // }
    bool isFinished(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    return false;
            }
        }
        return true;
    }
    bool allowedNum(vector<vector<char>>& board, int row, int col, int num)
    {
        // if its safe to keep num in board[row][col]
        // check if num in same row or col
        for(int i=0; i<9; i++)
        {
            if(board[row][i] - '0'==num || board[i][col] - '0'== num)
                return false;
        }
        // check if num in 3X3 grid
        for(int i=3*(row/3); i<3*(row/3)+3; i++)
        {
            for(int j=3*(col/3); j<3*(col/3)+3; j++)
            {
                if(board[i][j] - '0'==num)
                    return false;    
            }
        }
        return true;
    }
    bool solveSudokuUtil(vector<vector<char>>& board)
    {
        if(isFinished(board))
        {
            return true;    
        }
        else
        {
            for(int row=0;row<9;row++)
            {
                for(int col=0;col<9;col++)
                {
                    if(board[row][col]=='.')
                    {
                      for(int num=1;num<=9;num++)
                      {
                        if(allowedNum(board,row,col,num))
                        {
                            board[row][col] = num + '0';
                            if(solveSudokuUtil(board))
                                return true;
                        }
                      }
                    board[row][col] = '.';
                    return false;
                    }
                }
            }
            
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solveSudokuUtil(board);
    }
};