class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
        
        // Case 1: Product of the three largest numbers
        int option1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        
        // Case 2: Product of the two smallest (most negative) numbers and the largest number
        int option2 = nums[0] * nums[1] * nums[n - 1];
        
        // Return the maximum of both options
        return max(option1, option2);
    }
};
