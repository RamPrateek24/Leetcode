class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) return false;
        vector<vector<bool>> dp(nums.size()+1, vector<bool> (sum/2+1));
        for (int i = 0; i <= nums.size(); i++) dp[i][0] = true;
        for (int j = 1; j <= sum/2; j++) dp[0][j] = false;

        for(int i=1; i<=nums.size(); i++){
            for(int j=1; j<=sum/2; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = (dp[i-1][j - nums[i-1]] || dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
                if(j == sum/2 && dp[i][j] == true) return true; 
            }
        }
        return false;
    }
};