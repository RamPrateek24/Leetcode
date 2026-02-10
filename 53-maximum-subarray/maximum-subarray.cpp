class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx = INT_MIN;
        int sum = 0;
        for(auto &it: nums){
            sum += it;
            maxx = max(sum, maxx);
            if(sum < 0) sum = 0;
        }
        return maxx;
    }
};