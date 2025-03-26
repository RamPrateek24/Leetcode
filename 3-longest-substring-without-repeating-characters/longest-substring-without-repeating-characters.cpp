class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int l = 0, r = 0, maxx = 0;
            unordered_map<char, int> mpp;
            while(r<s.size()){
                if(mpp.find(s[r]) == mpp.end()){
                    mpp[s[r]] = r;
                    r++;
                }
                else{
                    l = max(mpp[s[r]] + 1, l);
                    mpp[s[r]] = r;
                    r++;
                }
                maxx = max(maxx, r-l);
            }
            return maxx;
    }
};