class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            map<char,int> mp_row;
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    mp_row[board[i][j]]++;
                    if(mp_row[board[i][j]] > 1)
                    {
                        cout<<"hello";
                        return false;   
                    }
                }
            }
            mp_row.clear();
        }
        for(int i=0;i<9;i++)
        {
            map<char,int> mp_col;
            for(int j=0;j<9;j++)
            {
                if(board[j][i] != '.')
                {
                    mp_col[board[j][i]]++;
                    if(mp_col[board[j][i]] > 1)
                    {
                        cout<<"hello2";
                        return false;   
                    }
                }
            }
            mp_col.clear();
        }
        int k = 0;
        int l = 0;
        while(k<9)
        {
            map<char,int> mp;
            for(int i=k;i<k+3;i++)
            {
                for(int j=l;j<l+3;j++)
                {
                    if(board[i][j] != '.')
                    {
                        mp[board[i][j]]++;
                        if(mp[board[i][j]] >1)
                        {
                            cout<<"hello3";
                            return false;   
                        }
                    }
                }      
            }
            l = l+3;
            if(l==9)
            {
                k = k+3;  
                l = 0;
            }
            mp.clear();
        }
        return true;
    }
};