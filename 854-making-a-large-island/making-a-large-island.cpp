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
vector<int> delr = {-1, 0, 1, 0};
vector<int> delc = {0, 1, 0, -1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint ds(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) continue;
                
                for(int ind = 0; ind < 4; ind++){
                    int nrow = i + delr[ind];
                    int ncol = j + delc[ind];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                        ds.unionbysize(i*n+j, nrow*n+ncol);
                    }
                }
            }
        }
        int maxx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) continue;
                set<int> components;
                for(int ind = 0; ind < 4; ind++){
                    int nrow = i + delr[ind];
                    int ncol = j + delc[ind];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                        components.insert(ds.findpar(nrow*n+ncol));
                    }
                }
                int tot = 0;
                for(auto it:components){
                    tot += ds.size[it];
                }
                maxx = max(maxx, tot+1);
            }
        }
        for(int i=0; i<n*n; i++){
            maxx = max(maxx, ds.size[ds.findpar(i)]);
        }
        return maxx;
    }
};