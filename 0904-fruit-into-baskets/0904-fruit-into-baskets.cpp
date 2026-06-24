class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int, int> basket;
        int left = 0;
        int max_fruits = 0;

        for (int right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;

            while (basket.size() > 2) {
                int left_fruit = fruits[left];
                basket[left_fruit]--;
                
                if (basket[left_fruit] == 0) {
                    basket.erase(left_fruit);
                }
                left++; 
            }

            max_fruits = max(max_fruits, right - left + 1);
        }

        return max_fruits;
    }
};
