class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeroes = 0, maxlen = 0;
        while(r<nums.size()){
            if(nums[r] == 0) zeroes++;
            if(zeroes<=k){
                maxlen = max(maxlen, r-l+1);
                r++;
            }   
            else{
                while(zeroes > k){
                    if(nums[l] == 0){
                        zeroes--;
                    }
                    l++;
                } 
                r++; 
            }
        }
        return maxlen;
    }
};