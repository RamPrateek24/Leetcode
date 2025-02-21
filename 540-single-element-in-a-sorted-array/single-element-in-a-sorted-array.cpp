class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, h = nums.size()-1;
        if(nums.size() == 1 || nums[0] != nums[1] ) return nums[0];
        if( nums[h] != nums[h-1]) return nums[h];
        while(l <= h){
            int mid = (l+h)/2;
            if((nums[mid-1] != nums[mid]) && (nums[mid+1] != nums[mid])) return nums[mid];
            if(mid%2==0){
                if(nums[mid] == nums[mid+1]){
                    l = mid+1;
                }
                else{
                    h = mid - 1;
                }
            }
            else{
                if(nums[mid] == nums[mid-1]){
                    l = mid+1;
                }
                else{
                    h = mid-1;
                }
            }
        }
        return 0;
    }
};