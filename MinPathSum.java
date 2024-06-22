class Solution {
    public int minPathSum(int[][] grid) {
        int rows = grid.length;
        int col = grid[0].length;
        int dp[][] = new int[rows][col];
        dp[0][0] = grid[0][0];
        for(int i=1; i<rows; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int j=1; j<col; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i=1; i<rows; i++) {
            for(int j=1; j<grid[i].length; j++) {
                dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        // for(int i=0; i<rows; i++) {
        //     for(int j=0; j<grid[i].length; j++) {
        //         System.out.print(dp[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        return dp[rows-1][col-1];
    }
}
