class Solution {
public:
    void para(int n, int open, int close, string s, vector<string> &v){
        if(s.size() == 2*n){
            v.push_back(s);
            return;
        }
        if(open < n){
            para(n, open+1, close, s + '(', v);
        }
        if(close < open){
            para(n, open, close+1, s+')', v);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        para(n, 0, 0, "", v);
        return v;
    }
};