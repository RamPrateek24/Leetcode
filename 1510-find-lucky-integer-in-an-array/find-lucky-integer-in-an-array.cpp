class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(auto& it:arr){
            mpp[it]++;
        }
        int maxx = -1;
        for(auto& it:arr){
            if(it == mpp[it]) maxx = max(maxx, mpp[it]);
        }
        return maxx;
    }
};