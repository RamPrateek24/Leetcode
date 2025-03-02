class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count=1, maxx=0;
        if(nums.empty()) return 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i]-nums[i-1] == 1){
                count++;
            }
            else{
                maxx = max(maxx, count);
                count = 1;
            }
        }
        return max(maxx, count);
    }
};