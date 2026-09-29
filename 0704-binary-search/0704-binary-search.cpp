class Solution {
public:
    int solve(vector<int>& nums, int l, int r, int target){
        if(l > r) return -1;
        int mid = l + (r-l)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) return solve(nums, mid+1, r, target);
        return solve(nums, l, mid-1, target);
    }
    int search(vector<int>& nums, int target) {
        return solve(nums, 0, nums.size()-1, target);
    }
};