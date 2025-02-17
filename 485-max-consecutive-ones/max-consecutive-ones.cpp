class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxx = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                count++;
            }
            else{
                maxx = max(count, maxx);
                count = 0;
            }
        }
        return max(maxx, count);
    }
};