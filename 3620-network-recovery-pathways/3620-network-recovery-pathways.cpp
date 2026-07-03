class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> in_degree(n, 0);
        vector<int> unique_costs;

        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            in_degree[edge[1]]++;
            unique_costs.push_back(edge[2]);
        }

        // Extract sorted unique values for binary search bounds
        sort(unique_costs.begin(), unique_costs.end());
        unique_costs.erase(unique(unique_costs.begin(), unique_costs.end()), unique_costs.end());

        // Compute Topological Sort once
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) q.push(i);
        }

        vector<int> topo_order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo_order.push_back(u);
            for (const auto& edge : adj[u]) {
                if (--in_degree[edge.first] == 0) {
                    q.push(edge.first);
                }
            }
        }

        // Iterative function to check path capability
        auto can_reach = [&](int threshold) -> bool {
            vector<long long> dp(n, 1e18); // 1e18 acts as infinity
            dp[0] = 0;

            for (int u : topo_order) {
                if (dp[u] == 1e18) continue;
                if (!online[u] && u != 0) continue;

                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int cost = edge.second;

                    if (cost >= threshold && online[v]) {
                        if (dp[u] + cost < dp[v]) {
                            dp[v] = dp[u] + cost;
                        }
                    }
                }
            }
            return dp[n - 1] <= k;
        };

        // Binary Search
        int low = 0, high = unique_costs.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can_reach(unique_costs[mid])) {
                ans = unique_costs[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
