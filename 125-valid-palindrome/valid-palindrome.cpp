class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> v;
        bool flag = true;
        for(int i=0; i<s.size(); i++){
            if(isalnum(s[i])){
                v.push_back(tolower(s[i]));
            }
        }
        for(int i=0; i<v.size()/2; i++){
            if(v[i]!=v[v.size()-1-i]){
                flag = false; 
                break;
            }
        }
        return flag;
    }
};