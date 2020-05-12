class Solution {
public:
    void dfs(vector <vector<int>> &image, int i, int j, int c, int o, vector <vector <bool>> visited)
    {
        
        if(i < 0 || i >= image.size() || j < 0 || j >= image[i].size() || image[i][j] != o)
        {
            
            return;
        }
        if(!visited[i][j])
        {
            image[i][j] = c;
            visited[i][j] = true;
            dfs(image, i+1, j, c, o, visited);
            dfs(image, i-1, j, c, o, visited);
            dfs(image, i, j-1, c, o, visited);
            dfs(image, i, j+1, c, o, visited);
            return;   
        }
        else
            return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        vector <vector <bool>> visited(image.size(), vector<bool> (image[0].size(), false));
        dfs(image, sr, sc, newColor, originalColor, visited);
        return image;
    }
};