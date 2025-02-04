class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> v;
        for(auto& it:nums){
            mpp[it]++;
        }
        for(auto & el:mpp){
            if(el.second == 1){
                v.push_back(el.first);
            }
        }
        return v;
    }
};