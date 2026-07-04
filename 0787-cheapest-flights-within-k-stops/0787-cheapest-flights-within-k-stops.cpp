class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto& f : flights){
            int u = f[0];
            int v = f[1];
            int cost = f[2];

            adj[u].push_back({v, cost});
        }

        vector<int> distance(n, INT_MAX);
        queue<pair<int, int>> que;

        que.push({src, 0});
        distance[src] = 0;

        int steps = 0;

        while(!que.empty() && steps <= k){
            int sz = que.size();

            while(sz--){
                int u = que.front().first;
                int cost = que.front().second;
                que.pop();

                for(auto& p : adj[u]){
                    int v = p.first;
                    int price = p.second;

                    if(distance[v] > price + cost){
                        distance[v] = price + cost;
                        que.push({v, price + cost});
                    }
                }

            }
            steps++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};