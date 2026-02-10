class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(auto &it: nums){
            if(it > 0) pos.push_back(it);
            else neg.push_back(it);
        }
        vector<int> v;
        for(int i=0; i<nums.size()/2; i++){
            v.push_back(pos[i]);
            v.push_back(neg[i]);
        }
        return v;
    }
};