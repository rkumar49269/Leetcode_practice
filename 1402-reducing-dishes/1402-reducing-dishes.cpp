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

        memset(dp, -1, sizeof(dp));

        return solve(satisfaction, 0, 1);
    }
};