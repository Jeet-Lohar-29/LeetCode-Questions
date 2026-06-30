class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            // Use a dummy height of 0 at index 'n' to flush out remaining elements in stack
            int current_height = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && heights[st.top()] > current_height) {
                int height = heights[st.top()];
                st.pop();
                
                // If stack is empty, the popped bar was the shortest seen so far (width is i)
                // Otherwise, the width is bounded between current index i and the new stack top
                int width = st.empty() ? i : (i - st.top() - 1);
                
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        
        return max_area;
    }
};
