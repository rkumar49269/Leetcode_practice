class Solution {
public:
    vector<int> dfs(unordered_map<int, vector<int>>& adj, int node, int parent, vector<int>& result, string& labels){
        vector<int> my_count(26, 0);
        char label = labels[node];

        my_count[label - 'a'] = 1;

        for(auto& v : adj[node]){
            if(v == parent) continue;

            vector<int> child_count(26, 0);
            child_count = dfs(adj, v, node, result, labels);

            for(int i = 0; i < 26; i++){
                my_count[i] += child_count[i];
            }

        }
        result[node] = my_count[label - 'a'];

        return my_count;
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
        dfs(adj, 0, -1, result, labels);

        return result;
    }
};