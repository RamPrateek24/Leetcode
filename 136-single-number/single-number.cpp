class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto & it:nums){
            mpp[it]++;
        }
        for(auto & el:mpp){
            if(el.second == 1){
                return el.first;
            }
        }
    return 0;
    }    
};