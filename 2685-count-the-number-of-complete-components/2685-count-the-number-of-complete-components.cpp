class Solution {
public:
    void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, int& v_count, int& deg_sum) {
        visited[u] = true;
        v_count++;
        deg_sum += adj[u].size();

        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited, v_count, deg_sum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int complete_components = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int v_count = 0;
                int deg_sum = 0;
                
                dfs(i, adj, visited, v_count, deg_sum);

                // A component is complete if total degree sum equals V * (V - 1)
                if (deg_sum == (long long)v_count * (v_count - 1)) {
                    complete_components++;
                }
            }
        }

        return complete_components;
    }
};
