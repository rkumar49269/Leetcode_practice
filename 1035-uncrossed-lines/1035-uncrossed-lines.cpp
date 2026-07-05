class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
        if(i >= nums1.size() || j >= nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(nums1[i] == nums2[j]) return dp[i][j] = 1 + solve(i+1, j+1, nums1, nums2);
        return dp[i][j] = max(solve(i+1, j, nums1, nums2), solve(i, j+1, nums1, nums2));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // memset(dp, -1, sizeof(dp));
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        for(int rows = 1; rows <= m; rows++){
            for(int cols = 1; cols <= n; cols++){
                if(nums1[rows-1] == nums2[cols-1]) t[rows][cols] = 1 + t[rows-1][cols-1];
                else t[rows][cols] = max(t[rows-1][cols], t[rows][cols-1]);
            }
        }

        return t[m][n];
        // return solve(0, 0, nums1, nums2);
    }
};