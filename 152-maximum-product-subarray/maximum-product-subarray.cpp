class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] < 0) swap(maxx, mini);
            maxx = max(nums[i], nums[i]*maxx);
            mini = min(nums[i], nums[i]*mini);
            ans = max(maxx, ans);
        }
        return ans;
    }
};