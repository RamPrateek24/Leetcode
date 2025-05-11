class Solution {
public:
    void solve(int col, vector<vector<string>> &ans, vector<string> &board, vector<int> &leftrow, vector<int> &upperd, vector<int> &lowerd, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(leftrow[row] == 0 && upperd[n-1+col-row] == 0 && lowerd[row+col] == 0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperd[n-1+col-row] = 1;
                lowerd[row+col] = 1;
                solve(col+1, ans, board, leftrow, upperd, lowerd, n);
                board[row][col] = '.';
                leftrow[row] = 0;
                upperd[n-1+col-row] = 0;
                lowerd[row+col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        vector<int> leftrow(n, 0);
        vector<int> upperd(2*n-1, 0);
        vector<int> lowerd(2*n-1, 0);
        solve(0, ans, board, leftrow, upperd, lowerd, n);
        return ans;
    }
};