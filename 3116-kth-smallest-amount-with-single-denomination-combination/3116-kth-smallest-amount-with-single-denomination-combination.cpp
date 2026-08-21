class Solution {
public:
    long long countSmaller(long long mid, vector<int>& coins){
        long long correctedCount = 0;
        int n = coins.size();

        for(int exp = 1; exp <= (1 << n) - 1; exp++){
            long long lcm = 0;
            long long order = 0;

            for(int i = 0; i < n ; i++){
                if(exp & (1 << i)){
                    order++;

                    if(lcm == 0) lcm = coins[i];
                    else lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                }
            }

            if(order % 2 == 0){
                correctedCount -= mid/lcm;
            }
            else {
                correctedCount += mid/lcm;
            }
        }
        return correctedCount;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long result = -1;
        long long l = 1;
        long long r = (long long)(*max_element(coins.begin(), coins.end())) * k;

        while(l <= r){
            long long mid = l + (r - l)/2;
            if(countSmaller(mid, coins) >= k){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return result;
    }
};