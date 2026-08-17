class Solution {
public:
    typedef long long ll;
    ll solve(ll n){
        ll cnt = 0;
        for(ll i = 1; i <= n; i *= 10){
            cnt += (n - i + 1);
        }
        return cnt;
    }
    int kthDigit(long long k) {
        if(k <= 9) return k;
        ll start = 1;
        ll end = 1e14;
        ll ans = -1;

        while(start <= end){
            ll mid = start + (end - start)/2;
            if(solve(10 * mid + 9) >= k){
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }

        ll curr = ans;
        ll prev = solve(10 * (curr -1) + 9);
        ll rem = k - prev - 1;
        ll d = to_string(10 * curr).size();

        ll q = rem / d;
        ll r = rem % d;

        ll num = 0;
        if(curr % 2 == 0) num = 10 * curr + q;
        else num = 10 * curr + 9 - q;

        string s = to_string(num);
        return s[r] - '0';
    }
};