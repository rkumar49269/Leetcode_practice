class Solution {
public:
    int dp[1001][1001];
    int n, m;
    int solve(string s, string t, int i, int j){
        if(j >= m) return 1;
        if(i >= n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(s[i] == t[j]){
            ans += solve(s, t, i+1, j+1) + solve(s, t, i+1, j);
        }
        else ans += solve(s, t, i+1, j);

        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        n = s.length();
        m = t.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, t, 0, 0);
    }
};