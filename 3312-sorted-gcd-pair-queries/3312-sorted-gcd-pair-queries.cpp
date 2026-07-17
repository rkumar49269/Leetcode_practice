class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());

        vector<int> divisorFreq(maxEl + 1, 0);
        for(int i = 0; i < n; i++){
            int num = nums[i];
            for(int j = 1; j*j <= num; j++){
                if(num % j == 0){
                    divisorFreq[j]++;
                    if(num/j != j) divisorFreq[num/j]++;
                }
            }
        }

        vector<long long> pairsWithGcd(maxEl + 1, 0);
        for(int g = maxEl; g >= 1; g--){
            long long cnt = divisorFreq[g];
            pairsWithGcd[g] = cnt * (cnt - 1)/2;

            for(int mul = 2*g; mul <= maxEl; mul += g){
                pairsWithGcd[g] -= pairsWithGcd[mul];
            }
        }

        vector<long long> prefixCountGcd(maxEl + 1, 0);
        for(int g = 1; g <= maxEl; g++){
            prefixCountGcd[g] = prefixCountGcd[g-1] + pairsWithGcd[g];
        }

        vector<int> ans;
        
        for(long long idx : queries){
            int l = 1;
            int r = maxEl;
            int temp = 1;

            while(l <= r){
                int mid_gcd = l + (r - l)/2;

                if(prefixCountGcd[mid_gcd] > idx){
                    temp = mid_gcd;
                    r = mid_gcd - 1;
                }
                else l = mid_gcd + 1;
            }

            ans.push_back(temp);
        }
        return ans;
    }
};