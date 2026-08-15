class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = nums[0];
        bool allzero = true;

        for(int i = 1; i < n; i++){
            xorr = xorr ^ nums[i];
            if(nums[i] > 0) allzero = false;
        }

        if(xorr > 0) return n;

        return allzero ? 0 : n-1;;
    }
};