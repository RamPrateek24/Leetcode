class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto& it: nums){
            mpp[it]++;
        }
        for(auto& el:mpp){
            if(el.second > 1){
                return true;
            }
        }
        return false;
    }
};