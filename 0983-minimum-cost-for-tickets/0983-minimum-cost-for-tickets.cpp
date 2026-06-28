class Solution {
public:
    int dp[366];
    int solve(int i, vector<int>& days, vector<int>& costs){
        if(i >= days.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int cost_1 = costs[0] + solve(i+1, days, costs);

        int max_7_days = days[i] + 7;
        int j = i;
        while(j < days.size() && days[j] < max_7_days) j++;
        int cost_7 = costs[1] + solve(j, days, costs);

        int max_30_days = days[i] + 30;
        int k = i;
        while(k < days.size() && days[k] < max_30_days) k++;
        int cost_30 = costs[2] + solve(k, days, costs);

        return dp[i] = min({cost_1, cost_7, cost_30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(0, days, costs);
    }
};