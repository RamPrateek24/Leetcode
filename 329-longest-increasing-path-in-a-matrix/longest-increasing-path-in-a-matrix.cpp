class Solution {
public:
    int n, m;
    vector<int> delr = {-1, 0, 1, 0};
    vector<int> delc = {0, 1, 0, -1};
    
    int dfs(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(dp[row][col] != -1) return dp[row][col];
        int maxx = 1;
        //vis[row][col] = 1;
        int val = matrix[row][col];
        for(int i=0; i<4; i++){
            int nrow = row + delr[i];
            int ncol = col + delc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && matrix[nrow][ncol] > val){
                maxx = max(maxx, 1+dfs(nrow, ncol, matrix, dp));
            }
        }
        return dp[row][col] = maxx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int ans = 1;
        //vector<vector<int>> vis(n, vector<int> (m));
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                   ans = max(ans, dfs(i, j, matrix, dp));
            }
        }
        return ans;
    }
};