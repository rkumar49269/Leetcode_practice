class Solution {
public:
    int solve(vector<int>& jobDifficulty, int n, int idx, int d, vector<vector<int>>& dp){
        if(d == 1){
            int maxD = jobDifficulty[idx];
            for(int i=idx;i<n;i++){
                maxD = max(maxD, jobDifficulty[i]);
            }
            return maxD;
        }

        if(dp[idx][d] != -1) return dp[idx][d];

        int maxD = jobDifficulty[idx];
        int finalMin = INT_MAX;

        for(int i=idx;i<=n-d;i++){
            maxD = max(maxD, jobDifficulty[i]);
            int res = maxD + solve(jobDifficulty, n, i+1, d-1, dp);
            finalMin = min(finalMin, res); 
        }
        return dp[idx][d] = finalMin;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        if(d > n) return -1;
        return solve(jobDifficulty, n, 0, d, dp);
    }
};