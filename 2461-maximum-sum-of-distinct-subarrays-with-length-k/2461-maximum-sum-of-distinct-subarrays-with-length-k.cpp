class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // Optimize standard I/O operations for competitive programming
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long current_sum = 0;
        long long max_sum = 0;
        int n = nums.size();
        
        // Tracks the element frequencies inside the current window
        unordered_map<int, int> counts;
        
        // 1. Process the initial window of size k
        for (int i = 0; i < k; ++i) {
            counts[nums[i]]++;
            current_sum += nums[i];
        }
        
        // If all elements in the first window are distinct, record the sum
        if (counts.size() == k) {
            max_sum = current_sum;
        }
        
        // 2. Slide the window across the rest of the array
        for (int i = k; i < n; ++i) {
            // Add the incoming element
            counts[nums[i]]++;
            current_sum += nums[i];
            
            // Remove the outgoing element
            int outgoing = nums[i - k];
            current_sum -= outgoing;
            
            if (--counts[outgoing] == 0) {
                counts.erase(outgoing);
            }
            
            // If the map size equals k, all elements in the window are unique
            if (counts.size() == k) {
                max_sum = max(max_sum, current_sum);
            }
        }
        
        return max_sum;
    }
};
