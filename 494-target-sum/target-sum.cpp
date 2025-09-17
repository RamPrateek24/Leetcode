class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int s2 = (sum+target)/2;
        if(target > sum || target < -sum || (sum+target)%2 != 0) return 0;
        vector<vector<int>> dp(n+1, vector<int> (s2+1, 0));
        dp[0][0] = 1;
        //int zeroes = count(nums.begin(), nums.end(), 0);
        for(int i=1; i<=n; i++){
            for(int j=0; j<=s2; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][s2];
    }
};