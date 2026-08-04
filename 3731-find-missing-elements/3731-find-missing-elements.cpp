class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        unordered_set<int> st;

        for(int x : nums){
            maxi = max(maxi, x);
            mini = min(mini, x);
            st.insert(x);
        }

        vector<int> ans;

        for(int i = mini; i <= maxi; i++){
            auto it = st.find(i);
            if(it == st.end()) ans.push_back(i);
        }

        return ans;
    }
};