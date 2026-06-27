class Solution {
public:
    int solve(string& s, int curr, int prev, vector<vector<int>>& dp){
        if(curr >= s.length()) return 0;

        if(dp[curr][prev] != -1) return dp[curr][prev];
        
        int flip = INT_MAX, no_flip = INT_MAX;

        if(s[curr] == '0'){
            if(prev == 0){
                flip = 1 + solve(s, curr+1, 1, dp);
                no_flip = solve(s, curr+1, 0, dp);
            }
            else{
                flip = 1 + solve(s, curr+1, 1, dp);
            }
        }
        else{
            if(prev == 0){
                flip = 1 + solve(s, curr+1, 0, dp);
                no_flip = solve(s, curr+1, 1, dp);
            }
            else{
                no_flip = solve(s, curr+1, 1, dp);
            }
        }
        return dp[curr][prev] = min(flip, no_flip);
    }
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(s, 0, 0, dp);
    }
};