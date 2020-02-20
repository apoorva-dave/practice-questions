void makeStar(vector<vector<char> > &b, int r, int c)
{
    if (r < 0 || r >= b.size() || c < 0 || c >= b[r].size() || b[r][c] != 'O') {
		return;
	}
	b[r][c] = '*';
	makeStar(b, r - 1, c);
	makeStar(b, r + 1, c);
	makeStar(b, r, c - 1);
	makeStar(b, r, c + 1);
}
void makeRowStar(vector<vector<char> > &A, int row)
{
    for(int i=0; i<A[row].size();i++)
    {
        if(A[row][i]=='O')
            makeStar(A,row,i);
    }
}
void makeColStar(vector<vector<char> > &A, int col)
{
    for(int i=0; i<A.size();i++)
    {
        if(A[i][col]=='O')
            makeStar(A,i,col);
    }
        
}
void Solution::solve(vector<vector<char> > &A) {
    if(A.size()==0)
        return;
    int rows = A.size();
    int cols = A[0].size();
    makeRowStar(A,0);
    makeColStar(A,cols-1);
    makeRowStar(A,rows-1);
    makeColStar(A,0);
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if(A[i][j]=='O')
                A[i][j] = 'X';
            if(A[i][j]=='*')
                A[i][j] = 'O';
        }
    }
}
