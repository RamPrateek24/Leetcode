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
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint ds(n);
        int count = 0;
        for(auto it:connections){
            if(ds.findpar(it[0]) == ds.findpar(it[1])) count++;
            else ds.unionbysize(it[0], it[1]);
        }
        int prov = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i) prov++;
        }
        if(prov - 1 <= count) return prov-1;
        return -1;
    }
};