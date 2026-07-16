class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        int i=0;

        for(int j=0; j<2*n; j=j+2){
            ans[j] = nums[i];
            ans[j+1] = nums[i+n];
            i++;
        }


        return ans;
    }
};