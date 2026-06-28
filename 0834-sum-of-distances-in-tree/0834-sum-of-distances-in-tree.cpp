class Solution {
public:
    long root_result = 0;
    vector<int> count;
    int N;
    int dfsRoot(unordered_map<int, vector<int>>& adj, int curr, int prev, int curr_depth){
        int total_count = 1;
        root_result += curr_depth;

        for(auto& c: adj[curr]){
            if(c == prev) continue;
            total_count += dfsRoot(adj, c, curr, curr_depth+1);
        }

        return count[curr] = total_count;
    }

    void dfs(unordered_map<int, vector<int>>& adj, int parent, int prev, vector<int>& result){
        for(int &c : adj[parent]){
            if(c == prev) continue;
            result[c] = result[parent] - count[c] + (N - count[c]);
            dfs(adj, c, parent, result);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        count.resize(n, 0);

        unordered_map<int, vector<int>> adj;

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfsRoot(adj, 0, -1, 0);

        vector<int> result(n, 0);
        result[0] = root_result;

        dfs(adj, 0, -1, result);

        return result;
    }
};