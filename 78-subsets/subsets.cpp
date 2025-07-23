class Solution {
public:
    void subs(int idx, vector<int> &ds, vector<int> arr, int n, vector<vector<int>> &ans){
        if(idx == n){
            ans.push_back(ds);
            return;
        }
        // if(ds.size() == 0){
        //     ans.push_back({});
        // }
        subs(idx+1, ds, arr, n, ans);
        ds.push_back(arr[idx]);
        subs(idx+1, ds, arr, n, ans);
        ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subs(0, ds, nums, nums.size(), ans);
        return ans;
    }
};