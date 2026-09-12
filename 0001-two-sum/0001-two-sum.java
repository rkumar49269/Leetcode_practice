class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        java.util.Map<Integer, Integer> map = new java.util.HashMap<>();

        for(int i = 0; i < n; i++){
            int two = target - nums[i];
            if(map.containsKey(two)){
                return new int[]{map.get(two), i};
            }

            map.put(nums[i], i);
        }

        return new int[] {};
    }
}