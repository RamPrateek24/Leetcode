class Disjoint{
    public:
    vector<int> size, parent;
    Disjoint(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findpar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findpar(parent[node]);
    }
    void unionbysize(int u,  int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_v] < size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        Disjoint ds(accounts.size());
        int n = accounts.size();
        sort(accounts.begin(), accounts.end());
        unordered_map<string, int> mapmailnode;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mapmailnode.find(accounts[i][j]) == mapmailnode.end()){
                    mapmailnode[accounts[i][j]] = i;
                }
                else{
                    ds.unionbysize(i, mapmailnode[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> mergemail(n);
        for(auto it:mapmailnode){
            int node = ds.findpar(it.second);
            mergemail[node].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(mergemail[i].size() == 0) continue;
            sort(mergemail[i].begin(), mergemail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto & it:mergemail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};