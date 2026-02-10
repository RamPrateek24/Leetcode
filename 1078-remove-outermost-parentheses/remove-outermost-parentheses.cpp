class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int d = 0;
        for(auto it: s){
            if(it == '('){
                if(d > 0){
                    res += it;
                }
                d++;
            }
            else{
                d--;
                if(d>0){
                    res += it;
                }
            }
        }
        return res;
    }
};