class Solution {
public:
    int getAlt(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int prev = nums[0] % 2;

        for (int i = 1; i < n; ++i) {
            int curr = nums[i] % 2;
            if ((prev + curr) % 2 == 1) { 
                count++;
                prev = curr;
            }
        }
        return count;
    }

    int getsame(vector<int>& nums) {
        int evenCount = 0, oddCount = 0;
        for (int num : nums) {
            if (num % 2 == 0) evenCount++;
            else oddCount++;
        }
        return max(evenCount, oddCount);
    }

    int maximumLength(vector<int>& nums) {
        int alt = getAlt(nums);
        int same = getsame(nums);
        return max(alt, same);
    }

};
