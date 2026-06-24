class Solution {
public:
    int solve(vector<int>& prices, int day, int n, bool buy, vector<vector<int>>& dp){
        if(day >= n) return 0;
        int profit = 0;

        if(dp[day][buy] != -1) return dp[day][buy];

        if(buy){
            int take = solve(prices, day+1, n, false, dp) - prices[day];
            int not_take = solve(prices, day+1, n, true, dp);
            profit = max({profit, take, not_take});
        }
        else{
            int sell = solve(prices, day+2, n, true, dp) + prices[day];
            int not_sell = solve(prices, day+1, n, false, dp);
            profit = max({profit, sell, not_sell});
        }
        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, prices.size(), true, dp);
    }
};