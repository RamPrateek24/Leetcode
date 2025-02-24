class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int k = 0;
      for(auto & it: nums){
        k ^= it;
      }
      return k;
    }    
};