class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int [] ans = new int[2];

        for(int i = 0; i < n; i++){
            int two = target - nums[i];
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(two == nums[j]){
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }
}