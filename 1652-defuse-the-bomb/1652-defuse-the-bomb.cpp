class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if (k == 0) return result;
        
        int start = 1, end = k;
        if (k < 0) {
            start = n + k;
            end = n - 1;
        }
        
        int current_window_sum = 0;
        for (int i = start; i <= end; ++i) {
            current_window_sum += code[i];
        }
        
        for (int i = 0; i < n; ++i) {
            result[i] = current_window_sum;
            
            current_window_sum -= code[start % n];
            start++;
            end++;
            current_window_sum += code[end % n];
        }
        
        return result;
    }
};
