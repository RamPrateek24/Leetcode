class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto & it: nums){
            mpp[it]++;
            if(mpp[it] == nums.size()/2) return it;
        }
        return 0;
    }
};