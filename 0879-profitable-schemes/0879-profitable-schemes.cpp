class Solution {
public:
    int MOD = 1e9+7;
    int dp[101][101][101];

    int solve(int i, int p, int cp, int &n, int &minProfit, vector<int>& group, vector<int>& profit){
        if(cp > n) return 0;
        if(i == group.size()){
            if(p >= minProfit) return 1;
            return 0;
        }

        if(dp[i][p][cp] != -1) return dp[i][p][cp];

        long long not_taken = solve(i+1, p, cp, n, minProfit, group, profit) % MOD;
        long long taken = solve(i+1, min(minProfit, profit[i]+p), group[i]+cp, n, minProfit, group, profit) % MOD;

        return dp[i][p][cp] = (taken + not_taken) % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, minProfit, group, profit);
    }
};