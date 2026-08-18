class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        unordered_set<int> st;

        int i = 0;
        int j = 0;

        while(j < n){
            if((j - i + 1) == k){
                for(int l = i; l <= j; l++){
                    st.insert(nums[l]);
                }

                for(int x : st) mp[x]++;

                st.erase(nums[i]);
                i++;
            }
            j++;
        }

        int result = -1;
        for(auto [num, count] : mp){
            if(count == 1 && num > result) result = num;
        }

        return result;
    }
};