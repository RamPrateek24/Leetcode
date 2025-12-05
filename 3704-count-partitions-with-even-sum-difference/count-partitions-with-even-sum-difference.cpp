class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int temp = 0, count = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) return 0;
        for(int it=0; it<nums.size()-1; it++){
            temp += nums[it];
            if((2*temp - sum)%2 == 0) count++;
        }
        return count;
    }
};