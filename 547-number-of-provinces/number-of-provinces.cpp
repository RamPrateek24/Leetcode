class Disjoint{
    vector<int> size, parent;
    public:
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
        
        void unionbysize(int u, int v){
            int ulp_u = findpar(u);
            int ulp_v = findpar(v);
            if(ulp_v == ulp_u) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    
};
class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        Disjoint ds(isConnected.size());
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected.size(); j++){
                if(isConnected[i][j] == 1) ds.unionbysize(i+1, j+1);
            }
        }
        for(int i=1; i<=isConnected.size(); i++){
            if(ds.findpar(i) == i) count++;
        }
        return count;
    }
};