class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, prefixsum = 0;
        unordered_map<int, int> mpp;
        mpp[0]++;
        for(auto& el:nums){
            prefixsum += el;
            int rem = prefixsum - k;
            count += mpp[rem];
            mpp[prefixsum]++;
        }
        
        return count;
    }
};