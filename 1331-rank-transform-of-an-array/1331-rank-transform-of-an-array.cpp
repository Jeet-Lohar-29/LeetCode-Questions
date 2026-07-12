class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Handle empty array edge case
        if (arr.empty()) return {};

        // Step 1: Create a sorted copy of the array
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());

        // Step 2: Assign ranks to unique elements
        unordered_map<int, int> rank_map;
        int rank = 1;
        for (int num : sorted_arr) {
            // Only assign rank and increment if the element isn't mapped yet
            if (rank_map.find(num) == rank_map.end()) {
                rank_map[num] = rank;
                rank++;
            }
        }

        // Step 3: Transform the original array into its ranks
        vector<int> result;
        result.reserve(arr.size());
        for (int num : arr) {
            result.push_back(rank_map[num]);
        }

        return result;
    }
};
