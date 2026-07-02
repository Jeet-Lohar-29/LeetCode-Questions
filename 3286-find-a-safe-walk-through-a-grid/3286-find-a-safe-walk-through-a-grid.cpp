class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> max_health(m, vector<int>(n, -1));
        priority_queue<pair<int, pair<int, int>>> pq; 
        
        int start_health = health - grid[0][0];
        if (start_health <= 0) return false;
        
        pq.push({start_health, {0, 0}});
        max_health[0][0] = start_health;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto [h, cell] = pq.top();
            pq.pop();
            int r = cell.first;
            int c = cell.second;
            
            if (r == m - 1 && c == n - 1) return h >= 1;
            if (h < max_health[r][c]) continue;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_health = h - grid[nr][nc];
                    if (next_health > max_health[nr][nc] && next_health >= 1) {
                        max_health[nr][nc] = next_health;
                        pq.push({next_health, {nr, nc}});
                    }
                }
            }
        }
        
        return false;
    }
};
