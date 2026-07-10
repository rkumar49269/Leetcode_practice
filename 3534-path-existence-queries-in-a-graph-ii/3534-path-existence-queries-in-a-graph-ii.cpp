class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        if (n == 0) return {};

        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[sorted_nodes[i].second] = i;
        }

        const int LOG = 18;
        vector<vector<int>> st(n, vector<int>(LOG, 0));

        int r = 0;
        for (int l = 0; l < n; ++l) {
            r = max(r, l);
            while (r + 1 < n && sorted_nodes[r + 1].first - sorted_nodes[l].first <= maxDiff) {
                r++;
            }
            st[l][0] = r;
        }

        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                int mid_point = st[i][j - 1];
                st[i][j] = st[mid_point][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int start_pos = pos[u];
            int end_pos = pos[v];

            if (start_pos > end_pos) {
                swap(start_pos, end_pos);
            }

            if (st[start_pos][0] == start_pos && start_pos < end_pos) {
                ans.push_back(-1);
                continue;
            }

            int steps = 0;
            int curr = start_pos;

            for (int j = LOG - 1; j >= 0; --j) {
                if (st[curr][j] < end_pos) {
                    steps += (1 << j);
                    curr = st[curr][j];
                }
            }

            if (st[curr][0] >= end_pos) {
                ans.push_back(steps + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};