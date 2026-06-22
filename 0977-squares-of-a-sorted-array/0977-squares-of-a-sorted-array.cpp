class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int i=0, j=n-1, idx=n-1;

        while(i <= j){
            int i2 = nums[i] * nums[i];
            int j2 = nums[j] * nums[j];
            if(i2 > j2){
                ans[idx] = i2;
                i++;
                idx--;
            }
            else{
                ans[idx] = j2;
                j--;
                idx--;
            }
        }
        return ans;
    }
};