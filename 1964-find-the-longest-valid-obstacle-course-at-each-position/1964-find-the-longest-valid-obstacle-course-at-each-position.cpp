class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> lis;
        

        // Code of LIS...
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //         if(obstacles[j] <= obstacles[i]){
        //             ans[i] = max(ans[i], ans[j] + 1);
        //         }
        //     }
        // }

        for(int i=0; i<n; i++){
            int idx = upper_bound(begin(lis), end(lis), obstacles[i]) - begin(lis);

            if(idx == lis.size()) lis.push_back(obstacles[i]);
            else lis[idx] = obstacles[i];

            ans[i] = idx + 1;
        }
        return ans;
    }
};