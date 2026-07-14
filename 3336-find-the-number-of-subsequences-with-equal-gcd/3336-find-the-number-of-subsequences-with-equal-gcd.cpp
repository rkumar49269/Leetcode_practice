class Solution {
public:
    int MOD = 1e9 + 7;
    int n;
    int dp[201][201][201];

    int solve(vector<int>& nums, int i, int first_gcd, int second_gcd){
        if(i == n) {
            bool bothNonEmpty = (first_gcd != 0 && second_gcd != 0);
            bool gcdMatch = (first_gcd == second_gcd);

            return (bothNonEmpty && gcdMatch) ? 1 : 0;
        }

        if(dp[i][first_gcd][second_gcd] != -1) return dp[i][first_gcd][second_gcd];

        int skip = solve(nums, i+1, first_gcd, second_gcd);
        int take1 = solve(nums, i+1, __gcd(first_gcd, nums[i]), second_gcd);
        int take2 = solve(nums, i+1, first_gcd, __gcd(second_gcd, nums[i]));

        return dp[i][first_gcd][second_gcd] = (0LL + skip + take1 + take2) % MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0);
    }
};