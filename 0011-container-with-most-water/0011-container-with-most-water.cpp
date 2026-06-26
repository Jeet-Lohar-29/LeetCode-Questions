class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Calculate the width between the current two lines
            int width = right - left;
            
            // The container height is limited by the shorter line
            int current_height = min(height[left], height[right]);
            
            // Calculate current water volume and update maximum
            int current_water = width * current_height;
            max_water = max(max_water, current_water);
            
            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};
