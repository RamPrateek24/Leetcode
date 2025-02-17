class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int r = 0, l = 0, ans = 0;
        long long int sum = 0;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(1LL * (r-l+1) * nums[r] > sum + k){
                sum -= nums[l];
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};