class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Initialize DSU tracking arrays locally
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Lambda helper function for finding group representative (with path compression)
        auto findGroup = [&](auto& self, int i) -> int {
            if (parent[i] == i) return i;
            return parent[i] = self(self, parent[i]);
        };

        // Lambda helper function to merge two separate groups together
        auto unionGroups = [&](int i, int j) {
            int root_i = findGroup(findGroup, i);
            int root_j = findGroup(findGroup, j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
            }
        };

        // Step 1: Link all connected cities together
        for (const auto& road : roads) {
            unionGroups(road[0], road[1]);
        }

        // Step 2: Grab the unique group ID of city 1
        int main_group = findGroup(findGroup, 1);
        int min_score = 1e9;

        // Step 3: Find the overall minimum distance road in this entire group
        for (const auto& road : roads) {
            if (findGroup(findGroup, road[0]) == main_group) {
                min_score = min(min_score, road[2]);
            }
        }

        return min_score;
    }
};
