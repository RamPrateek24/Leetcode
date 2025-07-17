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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxr = 0, maxc = 0;
        for(auto it: stones){
            maxr = max(maxr, it[0]);
            maxc = max(maxc, it[1]);
        }
        Disjoint ds(maxr + maxc + 1);
        set<int> st;
        for(auto & it: stones){
            int stoner = it[0];
            int stonec = it[1] + maxr + 1;
            ds.unionbysize(stoner, stonec);
            st.insert(stoner);
            st.insert(stonec);
        }
        int count = 0;
        for(auto it:st){
            if(ds.findpar(it) == it) count++;
        }
        return n-count;
    }
};