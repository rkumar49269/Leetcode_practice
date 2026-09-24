class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int digit = nums[i];
            int sum = 0;
            while(digit > 0){
                sum += (digit % 10);
                digit /= 10;
            }
            if(sum == i) return sum;
        }
        return -1;
    }
};