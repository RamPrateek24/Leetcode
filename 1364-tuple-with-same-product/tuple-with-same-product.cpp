class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int product = nums[i] * nums[j];
                count += mpp[product] * 8; 
                mpp[product]++;
            }
        }
       return count;
    }
};