class Solution {
public:
    int numberOfSubstrings(string s) {
        int counts[3] = {0};
        int start = 0;
        int result = 0;
        int n = s.length();

        for (int end = 0; end < n; ++end) {
            counts[s[end] - 'a']++;

            // Shrink the window from the left as long as it contains 'a', 'b',
            // and 'c'
            while (counts[0] > 0 && counts[1] > 0 && counts[2] > 0) {
                counts[s[start] - 'a']--;
                start++;
            }

            // All indices from 0 to start-1 can form a valid substring ending
            // at 'end'
            result += start;
        }

        return result;
    }
};