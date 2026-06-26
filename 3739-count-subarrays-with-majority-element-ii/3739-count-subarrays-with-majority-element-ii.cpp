#include <vector>

class Solution {
public:
    long long countMajoritySubarrays(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> bit(2 * n + 2, 0);
        
        auto add = [&](int idx, int val) {
            while (idx < bit.size()) {
                bit[idx] += val;
                idx += idx & (-idx);
            }
        };
        
        auto query = [&](int idx) {
            int s = 0;
            while (idx > 0) {
                s += bit[idx];
                idx -= idx & (-idx);
            }
            return s;
        };
        
        int offset = n + 1;
        add(offset, 1);
        
        int curr_sum = 0;
        long long ans = 0;
        
        for (int num : nums) {
            if (num == target) {
                curr_sum++;
            } else {
                curr_sum--;
            }
            
            ans += query(curr_sum - 1 + offset);
            add(curr_sum + offset, 1);
        }
        
        return ans;
    }
};