class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0], maxx = nums[0];
        int n = nums.size();
        vector<int> v;
        for(int i=1; i<=n-1; i++){
            if(nums[i-1]<nums[i]){
                sum += nums[i];
            }
            else{
                maxx = max(maxx, sum);
                sum = nums[i];
            }
            
        }
        return max(maxx, sum);
    }
};