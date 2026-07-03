class Solution {
public:
    int result;
    int dfs(unordered_map<int, vector<int>>& adj, int node, int parent, string& s){
        int longest = 0;
        int second_longest = 0;

        for(int & child : adj[node]){
            if(child == parent) continue;

            int child_longest = dfs(adj, child, node, s);

            if(s[child] == s[node]) continue;

            if(child_longest > second_longest){
                second_longest = child_longest;
            }

            if(second_longest > longest){
                swap(longest, second_longest);
            }
        }

        int koi_ek_acha = max(longest, second_longest) + 1;
        int only_node_acha = 1;
        int neeche_ka_hi_accha = 1 + longest + second_longest;

        result = max({result, koi_ek_acha, only_node_acha, neeche_ka_hi_accha});

        return max({koi_ek_acha, only_node_acha});
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int, vector<int>> adj;

        result = 0;

        for(int i = 1; i < n; i++){
            int u = i;
            int v = parent[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(adj, 0, -1, s);

        return result;
    }
};