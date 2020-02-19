struct cell{
  int x;
  int y;
  int dist;
  cell() {}
  cell(int x,int y, int dist) : x(x), y(y), dist(dist) {} 
};
bool isInside(int x, int y, int A, int B)
{
    if((x>=0 && x<A) && (y>=0 && y<B))
        return true;
    return false;
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    // knight can move 8 places from 1 position
    queue <cell> q;
    vector <vector<bool>> visited(A, vector <bool> (B,false));
    cell src(C-1,D-1,0);
    q.push(src);
    visited[C-1][D-1] = true;
    int dx[] = {-2,2,2,-2,1,-1,1,-1};
    int dy[] = {-1,-1,1,1,-2,-2,2,2};
    int x,y;
    while(!q.empty())
    {
        cell c = q.front();
        q.pop();
        if(c.x == E-1 && c.y == F-1)
            return c.dist;
        for(int i=0;i<8;i++)
        {
            x = c.x + dx[i];
            y = c.y + dy[i];
            if(isInside(x,y,A,B) && !visited[x][y])
            {
                cell k(x,y,c.dist+1);
                q.push(k);
                visited[x][y] = true;
            }
        }
    }
    return -1;
}
