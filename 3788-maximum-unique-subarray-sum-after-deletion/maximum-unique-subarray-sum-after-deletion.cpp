class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        for(auto it:nums){
            if(it <= 0) continue;
            s.insert(it);
        }
        if(s.size() == 0){
            sort(nums.begin(), nums.end());
            return nums[nums.size()-1];
        }
        int sum = 0;
        for(auto it:s){
            sum += it;
        }
        return sum;
    }
};