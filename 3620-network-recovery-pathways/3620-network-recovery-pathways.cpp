class Solution {
public:
    typedef pair<long long, int> P;

    bool check(int mid, int n, long long k, unordered_map<int, vector<pair<int, int>>>& adj){
        vector<long long> result(n, LLONG_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;

        result[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > k) return false;

            if(node == n-1) return true;

            if(result[node] < d) continue;

            for(auto& vec: adj[node]){
                int ngbr = vec.first;
                int cost = vec.second;

                if(cost < mid) continue;

                if(d + cost < result[ngbr]){
                    result[ngbr] = d + cost;
                    pq.push({d + cost, ngbr});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        int l = INT_MAX;
        int r = INT_MIN;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if(!online[u] || !online[v]){
                continue;
            }

            adj[u].push_back({v, cost});
            l = min(l, cost);
            r = max(r, cost);
        }

        int answer = -1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(check(mid, n, k, adj)){
                answer = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return answer;
    }
};