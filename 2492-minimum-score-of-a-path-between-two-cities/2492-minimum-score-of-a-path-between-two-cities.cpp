class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        // Tracking array for the minimum edge found along paths
        vector<int> min_edge_to(n + 1, 1e9);
        queue<int> q;
        
        q.push(1);
        min_edge_to[1] = 1e9;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int dist = neighbor.second;

                int possible_score = min(min_edge_to[u], dist);
                // Incorrectly limits graph discovery based on path sequence scores
                if (possible_score < min_edge_to[v]) {
                    min_edge_to[v] = possible_score;
                    q.push(v);
                }
            }
        }

        return min_edge_to[n];
    }
};
