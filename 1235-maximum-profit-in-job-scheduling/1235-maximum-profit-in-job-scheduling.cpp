class Solution {
public:
    int getNext(vector<vector<int>>& job, int l, int end){
        int r = job.size()-1;
        int result = job.size()+1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(job[mid][0] >= end){
                result = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return result;
    }
    int solve(vector<vector<int>> &job, int i, vector<int>& dp){
        if(i >= job.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int next = getNext(job, i+1, job[i][1]);
        int taken = job[i][2] + solve(job, next, dp);
        int notTaken = solve(job, i+1, dp);

        return dp[i] = max(taken, notTaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> job(n, vector<int>(3, 0));
        vector<int> dp(n+1, -1);

        for(int i=0; i<n; i++){
            job[i][0] = startTime[i];
            job[i][1] = endTime[i];
            job[i][2] = profit[i];
        }

        sort(job.begin(), job.end());

        return solve(job, 0, dp);
    }
};