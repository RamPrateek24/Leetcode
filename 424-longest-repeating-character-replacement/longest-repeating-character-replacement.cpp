class Solution {
public:
    int characterReplacement(string s, int k) {
        int p1 = 0, maxx = 0, ans = 0;
        unordered_map<char, int> mpp;

        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
            maxx = max(maxx, mpp[s[i]]);
            while((i - p1 + 1)- maxx > k){
                mpp[s[p1]]--;
                p1++;
            }
            ans = max(ans, i - p1 + 1);
        }
        return ans;
    }
};