class Solution {
public:
    int n, m;
    long long MOD = 1e9 + 7;
    int dp[55][55][15];

    int solve(int i, int j, int k, vector<vector<int>>& apple){
        if(apple[i][j] < k) return 0;
        if(k == 1){
            if(apple[i][j] >= 1) return 1;
            return 0;
        }

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int ans = 0;
        
        for(int h = i+1; h<m; h++){
            int lo_apple = apple[h][j];
            int up_apple = apple[i][j] - lo_apple;

            if(up_apple >= 1 && lo_apple >= k-1){
                ans = (ans % MOD + solve(h, j, k-1, apple) % MOD) % MOD;
            }
        }

        for(int v = j+1; v<n; v++){
            int ri_apple = apple[i][v];
            int lf_apple = apple[i][j] - ri_apple;

            if(lf_apple >= 1 && ri_apple >= k-1){
                ans = (ans % MOD + solve(i, v, k-1, apple) % MOD) % MOD;
            }
        }

        return dp[i][j][k] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();

        memset(dp, -1, sizeof(dp));

        vector<vector<int>> apple(m+1, vector<int>(n+1, 0));

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                apple[i][j] = apple[i][j+1];
                for(int l=i; l<m; l++){
                    if(pizza[l][j] == 'A') apple[i][j] += 1;
                }
            }
        }

        return solve(0, 0, k, apple);
    }
};