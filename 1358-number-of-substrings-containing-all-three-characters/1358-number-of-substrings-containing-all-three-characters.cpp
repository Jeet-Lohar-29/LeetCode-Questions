class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1};
        int result = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
            
            // The number of valid substrings ending at i is determined 
            // by the furthest left character of the three.
            int min_idx = min({last[0], last[1], last[2]});
            result += (min_idx + 1);
        }
        
        return result;
    }
};
