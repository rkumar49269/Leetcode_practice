class Solution {
public:
    void dfs(vector<vector<int>>& graph, int u, int v, vector<vector<int>>& result, vector<int>& temp){
        temp.push_back(u);
        if(u == v){
            result.push_back(temp);
        }
        else {
            for(int &x : graph[u]){
                dfs(graph, x, v, result, temp);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp;
        int n = graph.size();

        dfs(graph, 0, n-1, result, temp);
        return result;
    }
};