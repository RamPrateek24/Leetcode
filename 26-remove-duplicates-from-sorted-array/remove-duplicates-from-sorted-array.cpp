class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        //int n = s.size();
        nums.assign(s.begin(), s.end());
        
        return nums.size();
    }
};