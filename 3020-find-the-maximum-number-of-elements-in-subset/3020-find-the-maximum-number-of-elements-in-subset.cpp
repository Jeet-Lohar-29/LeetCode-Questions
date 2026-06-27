class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        int max_len = 1;
        
        // 1. Handle the base case of 1s (must be the largest odd count)
        if (count.find(1) != count.end()) {
            int ones_count = count[1];
            if (ones_count % 2 == 0) {
                ones_count--;
            }
            max_len = max(max_len, ones_count);
        }
        
        // 2. Handle numbers > 1
        for (auto& [x, freq] : count) {
            if (x == 1) continue;
            
            int current_len = 0;
            long long curr = x;
            
            // Keep matching pairs for outer layers of the pattern
            while (count.find(curr) != count.end() && count[curr] >= 2) {
                current_len += 2;
                curr = curr * curr; // safe from overflow due to long long
            }
            
            // If the next square exists at least once, it serves as the peak
            if (count.find(curr) != count.end() && count[curr] >= 1) {
                current_len += 1;
            } else {
                // If no peak is available, borrow 1 element from the final pair to make it the peak
                current_len -= 1;
            }
            
            max_len = max(max_len, current_len);
        }
        
        return max_len;
    }
};
