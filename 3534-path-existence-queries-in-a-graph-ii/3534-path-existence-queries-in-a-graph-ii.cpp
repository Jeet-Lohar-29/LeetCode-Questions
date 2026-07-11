class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Track {value, original_index}
        vector<pair<int, int>> sorted_nums(n);
        vector<int> rev_map(n); // Maps original index to its sorted index position
        
        for (int i = 0; i < n; ++i) {
            sorted_nums[i] = {nums[i], i};
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < n; ++i) {
            rev_map[sorted_nums[i].second] = i;
        }

        // Binary Lifting Sparse Tables (up to 2^17 = 131,072 steps)
        int LOG = 18;
        vector<vector<int>> up_right(n, vector<int>(LOG));

        // Step 1: Precalculate base optimal greedy step bounds
        for (int i = 0; i < n; ++i) {
            auto it_r = upper_bound(sorted_nums.begin(), sorted_nums.end(), 
                                    make_pair(sorted_nums[i].first + maxDiff, (int)1e9));
            int r_idx = distance(sorted_nums.begin(), it_r) - 1;
            up_right[i][0] = r_idx;
        }

        // Step 2: Build the complete binary sparse jump matrix
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                up_right[i][j] = up_right[up_right[i][j - 1]][j - 1];
            }
        }

        // Step 3: Process queries sequentially in O(log N) time
        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {
            int u = rev_map[q[0]];
            int v = rev_map[q[1]];

            if (u == v) {
                answer.push_back(0);
                continue;
            }
            if (u > v) swap(u, v); // Enforce left-to-right orientation

            // If the absolute maximum reachable range cannot cross v, it's a broken component
            if (up_right[u][LOG - 1] < v) {
                answer.push_back(-1);
                continue;
            }

            // Leap towards target v via binary lifting
            int steps = 0;
            int curr = u;
            for (int j = LOG - 1; j >= 0; --j) {
                if (up_right[curr][j] < v) {
                    steps += (1 << j);
                    curr = up_right[curr][j];
                }
            }
            
            // Add final closing step to cross or hit target v index position
            answer.push_back(steps + 1);
        }

        return answer;
    }
};
