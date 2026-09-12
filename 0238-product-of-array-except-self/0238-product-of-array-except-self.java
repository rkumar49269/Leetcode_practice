class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int [] ans = new int[n];
        int prod = 1;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0) prod *= nums[i];
            else cnt++;
        }

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                if(cnt > 0) ans[i] = 0;
                else ans[i] = prod/nums[i];
            }
            else{
                if(cnt > 1) ans[i] = 0;
                else ans[i] = prod;
            }
        }
        return ans;
    }
}