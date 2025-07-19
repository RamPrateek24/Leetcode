class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for(auto it:folder){
            if(ans.empty() || it.find(ans.back() + "/") != 0){
                ans.push_back(it);
            }
        }
        return ans;
    }
};