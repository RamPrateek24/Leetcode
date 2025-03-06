class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2, -1);
        if(distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target)) == nums.size() || nums[distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target))] != target) return v;
        v[0] = (distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target)));
        v[1] = (distance(nums.begin(), upper_bound(nums.begin(), nums.end(), target))) - 1;
        return v;
    }
};
