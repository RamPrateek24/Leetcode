class Solution {
public:
    int func(string &s, string &t, int n, int m, vector<vector<int>> &dp){
        if(n < 0 || m < 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s[n] == t[m]) return dp[n][m] = 1 + func(s, t, n-1, m-1, dp);
        return dp[n][m] = max(func(s, t, n-1, m, dp), func(s, t, n, m-1, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return func(s, t, n-1, n-1, dp);
    }
};