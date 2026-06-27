class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0); // Initialize all days with 0
        stack<int> st;            // Monotonic stack to store array indices
        
        for (int i = 0; i < n; ++i) {
            // While the current day is warmer than the day at the top of our stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev_index = st.top();
                st.pop();
                // Distance in days is the difference between current and previous index
                answer[prev_index] = i - prev_index;
            }
            // Push current index onto stack
            st.push(i);
        }
        
        return answer;
    }
};
