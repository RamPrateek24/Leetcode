class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        bool flag = true;
        for(int i=0; i<size(s); i++){
            if(s[i] == s[size(s) - i - 1]){
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
        return flag;
    }
};