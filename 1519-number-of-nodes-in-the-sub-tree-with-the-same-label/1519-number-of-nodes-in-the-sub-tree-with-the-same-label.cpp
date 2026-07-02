class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int node, int parent, vector<int>& result, string& labels, vector<int>& count){
        char label = labels[node];

        int before = count[label - 'a'];

        count[label - 'a'] += 1;

        for(auto& v : adj[node]){
            if(v == parent) continue;

            dfs(adj, v, node, result, labels, count);

        }
        
        int after = count[label - 'a'];

        result[node] = after - before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(n, 0);
        vector<int> count(26, 0);

        dfs(adj, 0, -1, result, labels, count);

        return result;
    }
};