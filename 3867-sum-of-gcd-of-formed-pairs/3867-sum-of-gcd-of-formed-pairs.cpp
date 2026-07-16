class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int mx = INT_MIN;

        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            prefixGcd[i] = __gcd(mx, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0, j = n-1;
        long long sum = 0;
        while(i < j){
            sum += __gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};