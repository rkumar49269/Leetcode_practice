class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int s, vector<bool>& visited){
        visited[s] = true;
        for(auto& node : rooms[s]){
            if(!visited[node]){
                dfs(rooms, node, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);

        dfs(rooms, 0, visited);

        for(bool x : visited){
            if(!x) return false;
        }

        return true;
    }
};