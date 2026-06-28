class Solution {
public:
    int n;
    int dp[501][501];
    int solve(vector<int>& satisfaction, int i, int time){
        if(i >= n) return 0;

        if(dp[i][time] != -1) return dp[i][time];

        int include = time*satisfaction[i] + solve(satisfaction, i+1, time+1);
        int exclude = solve(satisfaction, i+1, time);

        return dp[i][time] = max(include, exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        n = satisfaction.size();

        // memset(dp, -1, sizeof(dp));

        // return solve(satisfaction, 0, 1);

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1e9));

        for(int i=0; i<n; i++){
            dp[i][0] = 0;
        }

        int maxSatisfaction = 0;

        dp[0][1] = satisfaction[0];

        for(int i=1; i<n; i++){
            for(int j=1; j<=n; j++){
                long long include = satisfaction[i] * j + dp[i-1][j-1];
                long long exclude = dp[i-1][j];

                dp[i][j] = max(include, exclude);
            }
        }

        for(int i=1; i<=n; i++){
            maxSatisfaction = max(maxSatisfaction, dp[n-1][i]);
        }

        return maxSatisfaction;
    }
};