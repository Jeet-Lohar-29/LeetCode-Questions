class Solution {
public:
    int findGCD(vector<int>& nums) {
        // Find both the minimum and maximum elements in a single pass
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        
        // Calculate and return the greatest common divisor
        return gcd(*min_it, *max_it);
    }
};
