class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m));
        queue<pair<int, pair<int, int>>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({0, {i, j}});
                }
            }
        }
        vector<int> delr = {-1, 0, 1, 0};
        vector<int> delc = {0, 1, 0, -1};
        int maxx = 0;
        while(!q.empty()){
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            maxx = max(maxx, t);
            for(int i=0; i<4; i++){
                int nrow = r+delr[i];
                int ncol = c+delc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({t+1, {nrow, ncol}});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1) return -1;
            }
        }
        return maxx;
    }
};