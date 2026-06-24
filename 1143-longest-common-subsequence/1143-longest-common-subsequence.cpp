class Solution {
public:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
        if(i >= s1.length() || j >= s2.length()) return 0;
        if(s1[i] == s2[j]) return 1 + solve(s1, s2, i+1, j+1, dp);
        if(dp[i][j] != -1) return dp[i][j];

        int pick = solve(s1, s2, i+1, j, dp);
        int notPick = solve(s1, s2, i, j+1, dp);

        return dp[i][j] = max(pick, notPick);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};