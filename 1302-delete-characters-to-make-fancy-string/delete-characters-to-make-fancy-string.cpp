class Solution {
public:
    string makeFancyString(string s) {
        unordered_map<char, int> mpp;
        string ans = "";
        char prev = s[0];
        ans += s[0];
        mpp[s[0]] = 1;
        for(int i=1; i<s.size(); i++){
            if(s[i] == prev){
                if(mpp[s[i]] >= 2) continue;
                else {
                    mpp[s[i]]++;
                    ans+=s[i];
                }
            }   
            else {
                ans += s[i];
                mpp[prev] = 0;
                prev = s[i];
                mpp[prev] = 1;
            }
        }
        return ans;
    }
};