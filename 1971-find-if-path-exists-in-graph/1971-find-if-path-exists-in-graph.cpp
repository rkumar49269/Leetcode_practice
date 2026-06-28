class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int s, int d, vector<bool>& visited){
        if(s == d) return true;
        if(visited[s]) return false;
        visited[s] = true;

        for(auto& node : adj[s]){
            if(dfs(adj, node, d, visited)) return true;
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj;

        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // return dfs(adj, source, destination, visited);

        queue<int> que;
        que.push(source);
        visited[source] = true;

        while(!que.empty()){
            int sz = que.size();

            while(sz--){
                int node = que.front();
                que.pop();

                if(node == destination) return true;

                for(auto& v : adj[node]){
                    if(!visited[v]){
                        que.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
        return false;
    }
};