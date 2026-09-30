class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') return;

        grid[i][j] = '$';

        dfs(grid, i, j+1, n, m);
        dfs(grid, i, j-1, n, m);
        dfs(grid, i+1, j, n, m);
        dfs(grid, i-1, j, n, m);
    }
    void bfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        queue<pair<int, int>> q;
        grid[i][j] = '$';
        q.push({i, j});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            for(auto & dir : directions){
                int i_ = it.first + dir[0];
                int j_ = it.second + dir[1];

                if(i_ < 0 || i_ >= n || j_ < 0 || j_ >= m || grid[i_][j_] != '1') continue;
                else{
                    q.push({i_, j_});
                    grid[i_][j_] = '$';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j, n, m);
                    islands++;
                }
            }
        }
        return islands;
    }
};