class Solution {
public:
    int pivot_idx(vector<int>& nums){
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l < r){
            int m = l + (r-l)/2;
            if(nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        return r;
    }
    int binarySearch(vector<int>& nums, int l, int r, int target){
        int ans = -1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] == target){
                ans = m;
                break;
            }
            else if(nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = pivot_idx(nums);

        int ans = binarySearch(nums, 0, pivot-1, target);
        if(ans != -1) return ans;
        ans = binarySearch(nums, pivot, n-1, target);
        return ans;
    }
};