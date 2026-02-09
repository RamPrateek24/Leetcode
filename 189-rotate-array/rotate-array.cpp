class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v = nums;
        for(int i = 0; i<nums.size(); i++){
            nums[(i+k)%nums.size()] = v[i];
        }
    }
};