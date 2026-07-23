class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases for very small permutations
        if (n == 1) return 1;
        if (n == 2) return 2; // Can form {1, 2}
        
        // For n >= 3, the reachable XOR values cover all values from 0 to (2^k - 1)
        // where 2^k is the smallest power of 2 strictly greater than n.
        int msb = 1;
        while (msb <= n) {
            msb <<= 1;
        }
        
        return msb;
    }
};