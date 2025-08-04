class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int left = 0, right = 0;
        int maxFruits = 0;
        int n = fruits.size();

        for (; right < n; ++right) {
            count[fruits[right]]++;
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0)
                    count.erase(fruits[left]);
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};