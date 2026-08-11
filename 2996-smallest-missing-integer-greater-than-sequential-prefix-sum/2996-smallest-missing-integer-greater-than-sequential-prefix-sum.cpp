class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        unordered_set<int> st(begin(nums), end(nums));

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1] + 1) sum += nums[i];
            else break;
        }

        while(st.count(sum)){
            sum++;
        }

        return sum;
    }
};