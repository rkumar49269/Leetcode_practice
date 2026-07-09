class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n);
        component[0] = 0;
        for(int i=1; i<n; i++){
            if(abs(nums[i]-nums[i-1]) <= maxDiff){
                component[i] = component[i-1];
            }
            else{
                component[i] = component[i-1] + 1;
            }
        }

        vector<bool> result;

        for(int i=0; i<queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];

            if(component[u] == component[v]) result.push_back(true);
            else result.push_back(false);
        }

        return result;
    }
};