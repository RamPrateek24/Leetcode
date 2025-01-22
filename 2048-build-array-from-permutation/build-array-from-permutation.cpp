class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> k;
        for(int i=0; i<nums.size(); i++){
        k.push_back(nums[nums[i]]);
        }
        return k;
    }

};