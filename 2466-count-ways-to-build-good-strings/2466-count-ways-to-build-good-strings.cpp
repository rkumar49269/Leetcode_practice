class Solution {
public:
    int MOD = 1e9+7;
    vector<int> dp;
    int solve(int i, int low, int high, int zero, int one){
        if(i > high) return 0;
        if(dp[i] != -1) return dp[i];

        bool addOne = false;
        if(i >= low) addOne = true;

        int o = solve(one + i, low, high, zero, one);
        int z = solve(zero + i, low, high, zero, one);

        return dp[i] = (addOne + o + z) % MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.assign(high+1, -1);
        return solve(0, low, high, zero, one);
    }
};