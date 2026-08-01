class Solution {
public:
    int n;
    int dp[21][21];

    int solve(int i, int j, vector<int>& nums){
        if(i > j) return 0;
        if(i == j) return nums[i];

        if(dp[i][j] != -1) return dp[i][j];

        int take_i = nums[i] + min(solve(i+2, j, nums), solve(i+1, j-1, nums));
        int take_j = nums[j] + min(solve(i+1, j-1, nums), solve(i, j-2, nums));

        return dp[i][j] = max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));

        int sum = accumulate(begin(nums), end(nums), 0);
        int p1 = solve(0, n-1, nums);
        if(p1 >= sum - p1) return true;
        return false;
    }
};