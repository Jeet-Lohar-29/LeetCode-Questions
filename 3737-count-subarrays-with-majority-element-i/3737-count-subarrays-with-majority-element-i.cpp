class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int valid_subarrays_count = 0;
        int current_prefix_score = 0;
        
        // Map to track frequencies of running prefix scores
        unordered_map<int, int> prefix_score_frequencies;
        
        // Base case: A prefix score of 0 occurs once before processing elements
        prefix_score_frequencies[0] = 1;
        
        for (int num : nums) {
            // Transform array: target acts as +1, any other number acts as -1
            current_prefix_score += (num == target) ? 1 : -1;
            
            // Count all previous prefix scores that are strictly less than current
            for (auto const& [previous_score, frequency] : prefix_score_frequencies) {
                if (previous_score < current_prefix_score) {
                    valid_subarrays_count += frequency;
                }
            }
            
            // Record the current prefix score
            prefix_score_frequencies[current_prefix_score]++;
        }
        
        return valid_subarrays_count;
    }
};
