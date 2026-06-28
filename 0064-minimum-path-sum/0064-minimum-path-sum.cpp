class Solution {
public:
    int m, n;
    int dp[201][201];
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i == m-1 && j == n-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        if(i == m-1) return dp[i][j] = grid[i][j] + solve(grid, i, j+1);
        else if(j == n-1) return dp[i][j] = grid[i][j] + solve(grid, i+1, j);
        else return dp[i][j] = grid[i][j] + min(solve(grid, i+1, j), solve(grid, i, j+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        // return solve(grid, 0, 0);
        dp[0][0] = grid[0][0];

        for(int i=1; i<n; i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        for(int i=1; i<m; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
    }
};