class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        if(n == 1) return (r-l+1);
        long long MOD = 1e9+7;
        int m = r-l+1;

        vector<long long> dpDown(m, 0);
        vector<long long> dpUp(m, 0);

        vector<long long> nextUp(m, 0);
        vector<long long> nextDown(m, 0);

        vector<long long> prefUp(m+1, 0);
        vector<long long> prefDown(m+1, 0);

        for(int i=0;i<m;i++){
            dpUp[i] = i;
            dpDown[i] = m-i-1;
        }

        for(int i=3;i<=n;i++){
            // prefUp[0] = 0;
            // prefDown[0] = 0;

            for(int i=0;i<m;i++){
                prefUp[i+1] = (prefUp[i] + dpUp[i]) % MOD;
                prefDown[i+1] = (prefDown[i] + dpDown[i]) % MOD;
            }

            for(int i=0;i<m;i++){
                nextUp[i] = prefDown[i];
                nextDown[i] = (prefUp[m] - prefUp[i+1] + MOD) % MOD;
            }

            dpUp = nextUp;
            dpDown = nextDown;
        }

        long long total = 0;
        for(int i=0;i<m;i++){
            total = (total + dpUp[i] + dpDown[i]) % MOD;
        }
        return total;
    }
};