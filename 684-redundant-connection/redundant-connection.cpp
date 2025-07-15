class Solution {
public:
    vector<int> parent, size;
    int findpar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findpar(parent[node]);
    }
    bool unionbysize(int u, int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u == ulp_v) return false;
        parent[ulp_u] = ulp_v;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        for(auto & it:edges){
            if(!unionbysize(it[0], it[1])) return {it[0], it[1]};
        }
        return {};
    }
};