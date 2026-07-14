class Solution {
private:
    const int MOD = 1e9 + 7;
    // dp[idx][gcd1][gcd2]
    vector<vector<vector<int>>> memo;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int solve(int idx, int g1, int g2, vector<int>& nums) {
        if (idx == nums.size()) {
            return (g1 > 0 && g1 == g2) ? 1 : 0;
        }

        if (memo[idx][g1][g2] != -1) return memo[idx][g1][g2];

        long long ans = solve(idx + 1, g1, g2, nums);
        ans = (ans + solve(idx + 1, g1 == 0 ? nums[idx] : gcd(g1, nums[idx]), g2, nums)) % MOD;
        ans = (ans + solve(idx + 1, g1, g2 == 0 ? nums[idx] : gcd(g2, nums[idx]), nums)) % MOD;

        return memo[idx][g1][g2] = ans;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        // Constraints state max value is 200
        memo.assign(n, vector<vector<int>>(201, vector<int>(201, -1)));
        return solve(0, 0, 0, nums);
    }
};
