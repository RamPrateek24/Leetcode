class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int k = accumulate(nums.begin(), nums.end(), 0);
        return n*(n+1)/2 -k;
    }
};