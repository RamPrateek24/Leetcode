class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2, -1);
        int l1 = 0, r1 = nums.size() - 1, res1 = -1;
        
        while (l1 <= r1) {
            int mid1 = l1 + (r1 - l1) / 2;
            if (nums[mid1] >= target) r1 = mid1 - 1;
            else l1 = mid1 + 1;
            if (nums[mid1] == target) res1 = mid1;
        }

        int l2 = 0, r2 = nums.size() - 1, res2 = -1;
        
        while (l2 <= r2) {
            int mid2 = l2 + (r2 - l2) / 2;
            if (nums[mid2] <= target) l2 = mid2 + 1;
            else r2 = mid2 - 1;
            if (nums[mid2] == target) res2 = mid2;
        }

        v[0] = res1;
        v[1] = res2;
        return v;
    }
};
