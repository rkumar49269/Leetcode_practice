class Solution {
public:
    vector<long long> dp;
    long long solve(int i, vector<vector<int>>& questions){
        if(i >= questions.size()) return 0;
        if(dp[i] != -1) return dp[i];

        long long pick = questions[i][0] + solve(i + questions[i][1] + 1, questions);
        long long skip = solve(i + 1, questions);

        return dp[i] = max(pick , skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.assign(n, -1);

        return solve(0, questions);
    }
};