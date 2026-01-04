class Solution {
public:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    void dfs(vector<vector<int>> &image, vector<vector<int>> & vis, int r, int c, int color, int ref){
        image[r][c] = color;
        vis[r][c] = 1;
        int n = image.size();
        int m = image[0].size();

        for(int i=0; i<4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol >=0 && !vis[nrow][ncol] && image[nrow][ncol] == ref){
            dfs(image, vis, nrow, ncol, color, ref);
            }
        } 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ref = image[sr][sc];
        dfs(image, vis, sr, sc, color, ref);
        return image;
    }
};