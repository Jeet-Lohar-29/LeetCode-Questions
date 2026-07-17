class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }
        
        // Count frequencies of each number
        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        // gcd_count[g] will store the exact number of pairs with GCD equal to g
        vector<long long> gcd_count(max_val + 1, 0);
        
        // Iterate backwards to apply inclusion-exclusion
        for (int g = max_val; g >= 1; g--) {
            long long total_multiples = 0;
            for (int multiple = g; multiple <= max_val; multiple += g) {
                total_multiples += count[multiple];
            }
            
            // Total possible pairs that share 'g' as a common divisor
            long long pairs = (total_multiples * (total_multiples - 1)) / 2;
            
            // Subtract pairs that have a strictly larger common multiple (e.g., 2g, 3g...)
            for (int multiple = 2 * g; multiple <= max_val; multiple += g) {
                pairs -= gcd_count[multiple];
            }
            gcd_count[g] = pairs;
        }
        
        // Create a prefix sum array of GCD counts to track indices
        vector<long long> pref(max_val + 1, 0);
        for (int i = 1; i <= max_val; i++) {
            pref[i] = pref[i - 1] + gcd_count[i];
        }
        
        // Process queries using binary search
        vector<int> answer;
        for (long long q : queries) {
            // Find the first GCD value whose prefix sum index is greater than q
            int idx = upper_bound(pref.begin(), pref.end(), q) - pref.begin();
            answer.push_back(idx);
        }
        
        return answer;
    }
};
