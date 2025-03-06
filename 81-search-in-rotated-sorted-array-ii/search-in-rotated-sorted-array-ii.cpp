class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, n = nums.size(), h=n-1;
        while(l<=h){
            int mid  = (l+h)/2;
            if(nums[mid] == target) return true;
            if(nums[l] == nums[mid] && nums[mid] ==  nums[h]){
                l += 1;
                h -= 1;
                continue;
            }
            if(nums[l] <= nums[mid]){
                if(target>=nums[l] && target<=nums[mid]){
                    h = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target<= nums[h]){
                    l = mid+1;
                }
                else{
                    h = mid-1;
                }
            }
        }
        return false;
    }
};