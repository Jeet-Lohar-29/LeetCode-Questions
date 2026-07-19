class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIdx(26, 0);
        vector<bool> seen(26, false);
        string result = "";
        
        // Track the last occurrence index of each character
        for (int i = 0; i < s.length(); i++) {
            lastIdx[s[i] - 'a'] = i;
        }
        
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            
            // Skip the character if it is already in our result string
            if (seen[curr - 'a']) {
                continue;
            }
            
            // Maintain lexicographically smallest order using a stack/string
            while (!result.empty() && result.back() > curr && lastIdx[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Add current character to result and mark it as seen
            result.push_back(curr);
            seen[curr - 'a'] = true;
        }
        
        return result;
    }
};
