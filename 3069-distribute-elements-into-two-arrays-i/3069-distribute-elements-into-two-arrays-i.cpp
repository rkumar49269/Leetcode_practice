class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2, result;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int prev1 = nums[0];
        int prev2 = nums[1];
        int i = 2;

        while(i < n){
            if(prev1 > prev2){
                arr1.push_back(nums[i]);
                prev1 = nums[i];
            }
            else {
                arr2.push_back(nums[i]);
                prev2 = nums[i];
            }
            i++;
        }

        for(int x : arr1) result.push_back(x);
        for(int x : arr2) result.push_back(x);

        return result;
    }
};