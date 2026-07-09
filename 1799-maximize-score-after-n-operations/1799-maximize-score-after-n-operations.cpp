class Solution {
public:
    int solve(vector<int>& nums, vector<bool>& visited, int operations, int n, unordered_map<vector<bool>, int>& mp){
        if(mp.find(visited) != mp.end()){
            return mp[visited];
        }
        
        int maxScore = 0;
        for(int i=0; i<n-1; i++){
            if(visited[i]) continue;
            for(int j=i+1; j<n; j++){
                if(visited[j]) continue;
                visited[i] = true;
                visited[j] = true;

                int score = operations * __gcd(nums[i], nums[j]);
                int remScore = solve(nums, visited, operations+1, n, mp);

                visited[i] = false;
                visited[j] = false;

                maxScore = max(maxScore, score + remScore);
            }
        }
        return mp[visited] = maxScore;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        unordered_map<vector<bool>, int> mp;

        return solve(nums, visited, 1, n, mp);
    }
};