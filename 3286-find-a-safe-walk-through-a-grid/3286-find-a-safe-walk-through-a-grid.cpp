class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, pair<int, int>>> que;

        vector<vector<int>> max_health(m, vector<int>(n, -1));

        int start_health = health - grid[0][0];
        if(start_health <= 0) return false;

        que.push({start_health, {0, 0}});
        max_health[0][0] = start_health;

        while(!que.empty()){
            auto curr = que.front();
            que.pop();

            int curr_health = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            if(curr_health < max_health[i][j]) continue;

            if(i == m-1 && j == n-1 && curr_health > 0) return true;

            for(auto& dir : directions){
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                    int next_health = curr_health - grid[new_i][new_j];

                    if(next_health > max_health[new_i][new_j] && next_health > 0){
                        que.push({next_health, {new_i, new_j}});
                        max_health[new_i][new_j] = next_health;
                    }
                }
            }
        }
        return false;
    }
};