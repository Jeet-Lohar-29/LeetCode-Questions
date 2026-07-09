class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // breaks[i] stores the number of connectivity breaks up to index i
        vector<int> breaks(n, 0);
        
        for (int i = 1; i < n; i++) {
            breaks[i] = breaks[i - 1];
            if (nums[i] - nums[i - 1] > maxDiff) {
                breaks[i]++;
            }
        }
        
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            if (u == v) {
                answer.push_back(true);
                continue;
            }
            
            int left = min(u, v);
            int right = max(u, v);
            
            // If the number of breaks between left and right is 0, a path exists
            int total_breaks_in_range = breaks[right] - breaks[left];
            answer.push_back(total_breaks_in_range == 0);
        }
        
        return answer;
    }
};
