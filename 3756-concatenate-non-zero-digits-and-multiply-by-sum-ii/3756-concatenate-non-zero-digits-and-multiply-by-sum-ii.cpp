class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        // Prefix optimization arrays
        vector<long long> pref_val(m + 1, 0);
        vector<int> pref_count(m + 1, 0);
        vector<long long> pref_sum(m + 1, 0);
        vector<long long> power10(m + 1, 1);

        // Precompute powers of 10 modulo 10^9 + 7
        for (int i = 1; i <= m; ++i) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        // Fill prefix structures
        for (int i = 0; i < m; ++i) {
            pref_val[i + 1] = pref_val[i];
            pref_count[i + 1] = pref_count[i];
            pref_sum[i + 1] = pref_sum[i];

            if (s[i] != '0') {
                int digit = s[i] - '0';
                pref_val[i + 1] = (pref_val[i] * 10 + digit) % MOD;
                pref_count[i + 1]++;
                pref_sum[i + 1] += digit;
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());

        // Process each query in O(1) time
        for (const auto& q : queries) {
            int l = q[0], r = q[1];

            // 1. Get the total number of non-zero digits in the range
            int non_zero_count = pref_count[r + 1] - pref_count[l];

            if (non_zero_count == 0) {
                answer.push_back(0);
                continue;
            }

            // 2. Extract the prefix numeric value 'x' via modular subtraction
            long long x = (pref_val[r + 1] - (pref_val[l] * power10[non_zero_count]) % MOD + MOD) % MOD;

            // 3. Extract the total face value sum
            long long sum = pref_sum[r + 1] - pref_sum[l];

            // 4. Calculate the final answer product
            long long current_ans = (x * (sum % MOD)) % MOD;
            answer.push_back(current_ans);
        }

        return answer;
    }
};
