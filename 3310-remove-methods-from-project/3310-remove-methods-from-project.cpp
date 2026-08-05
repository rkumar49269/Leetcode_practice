class Solution {
public:
    void dfs(int u, vector<bool>& visited, unordered_map<int, vector<int>>& adj){
        visited[u] = true;
        for(auto& v : adj[u]){
            if(!visited[v]){
                dfs(v, visited, adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj(n);
        for(auto& edge : invocations){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<bool> visited(n, false);

        dfs(k, visited, adj);

        for(auto& edge : invocations){
            int u = edge[0];
            int v = edge[1];

            if(!visited[u] && visited[v]){
                vector<int> ans(n);
                for(int i = 0; i < n; i++) ans[i] = i;
                return ans;
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};