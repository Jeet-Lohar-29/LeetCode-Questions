class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<bool> removed(n, false);
        int remaining_count = n;

        // Compare every interval with every other interval
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || removed[i]) continue;

                // Check if interval i is fully covered by interval j
                if (intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1]) {
                    removed[i] = true;
                    remaining_count--;
                    break; // Move to the next interval since i is already removed
                }
            }
        }

        return remaining_count;
    }
};
