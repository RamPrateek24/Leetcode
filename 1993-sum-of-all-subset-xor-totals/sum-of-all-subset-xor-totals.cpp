class Solution {
public:
    vector<vector<int>> func(vector<int> v){
        int n = v.size();
        vector<vector<int>> ans;
        for(int i=0; i< (1<<n); i++){
            vector<int> z;
            for(int j=0; j<n; j++){
                if((i&(1<<j))){
                    z.push_back(v[j]);
                }
            }
            ans.push_back(z);
        }
        return ans;
    }
    int subsetXORSum(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int sum = 0;
        vector<vector<int>> ans = func(nums);
        for(int i=0; i<ans.size(); i++){
            int z = 0;
            for(int j=0; j<ans[i].size(); j++){
                z ^= ans[i][j];
            }
            sum += z;
        }
        return sum;
    }
};