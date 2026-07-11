class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int i, int &v, int &e, vector<bool>& visited){
        visited[i] = true;
        e += adj[i].size();
        v++;
        for(auto& u : adj[i]){
            if(!visited[u]){
                dfs(adj, u, v, e, visited);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int result = 0;

        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            int v = 0;
            int e = 0;
            dfs(adj, i, v, e, visited);
            if((v*(v-1)) == e) result++;
        }
        return result;
    }
};