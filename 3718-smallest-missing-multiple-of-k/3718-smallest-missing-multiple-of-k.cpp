class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int x : nums){
            st.insert(x);
        }

        int t = k;
        int ans = 0;
        while(true){
            if(st.find(t) == st.end()){
                return t;
            }
            st.erase(t);
            t += k;
        }
    }
};