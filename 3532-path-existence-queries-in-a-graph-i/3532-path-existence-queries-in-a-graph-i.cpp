class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        // Lambda helper for finding component representative
        auto findComp = [&](auto& self, int i) -> int {
            if (parent[i] == i) return i;
            return parent[i] = self(self, parent[i]);
        };
        
        // Connect consecutive items if they satisfy maxDiff
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                int root1 = findComp(findComp, i);
                int root2 = findComp(findComp, i + 1);
                if (root1 != root2) {
                    parent[root1] = root2;
                }
            }
        }
        
        vector<bool> answer;
        answer.reserve(queries.size());
        
        // O(1) query time using component IDs
        for (const auto& q : queries) {
            answer.push_back(findComp(findComp, q[0]) == findComp(findComp, q[1]));
        }
        
        return answer;
    }
};
