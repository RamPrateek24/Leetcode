class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int j;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]<target){
                l = mid+1;
            }
            else if(nums[mid]>target){
                h = mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};