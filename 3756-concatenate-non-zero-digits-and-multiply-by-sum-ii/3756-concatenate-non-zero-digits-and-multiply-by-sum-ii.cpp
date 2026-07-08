class Solution {
public:
    int MOD = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        vector<int> nonzeroUpto(m, 0);
        vector<long long> digitSum(m, 0);
        vector<long long> numUpto(m, 0);
        vector<long long> power10(m+1, 0);
        
        digitSum[0] = s[0] - '0';
        nonzeroUpto[0] = (s[0] != '0') ? 1 : 0;
        numUpto[0] = s[0]-'0';
        power10[0] = 1;

        for(int i=1; i<m; i++){
            int digit = s[i]-'0';

            digitSum[i] = (digitSum[i-1] + digit) % MOD;
            nonzeroUpto[i] = nonzeroUpto[i-1] + ((digit != 0) ? 1 : 0);
            if(digit != 0){
                numUpto[i] = ((numUpto[i-1] * 10) + digit) % MOD;
            }
            else{
                numUpto[i] = numUpto[i-1];
            }
            power10[i] = (power10[i-1] * 10) % MOD;
        }

        int q = queries.size();
        vector<int> result(q);

        for(int i=0; i<q; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            long long sum = digitSum[r] - ((l == 0) ? 0 : digitSum[l-1]);

            long long num_b = (l == 0) ? 0 : numUpto[l-1];
            int k = nonzeroUpto[r] - ((l == 0) ? 0 : nonzeroUpto[l-1]);

            long long x = (numUpto[r] - (num_b * power10[k] % MOD) + MOD) % MOD;

            result[i] = (int) ((x * sum) % MOD);
        }
        return result;
    }
};