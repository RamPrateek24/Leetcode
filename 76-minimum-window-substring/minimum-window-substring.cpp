class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";
        unordered_map<char, int> mpp1, mpp2;
        for(auto & it: t){
            mpp1[it]++;
        } 
        int have = 0, need = mpp1.size(), mini = INT_MAX, p1 = 0;
        pair<int, int> pr;
        for(int i=0; i<s.size(); i++){
            mpp2[s[i]]++;
            if(mpp1.count(s[i]) && mpp1[s[i]] == mpp2[s[i]]) have++;
            while(have == need){
                if(i - p1 + 1 < mini){
                    mini = i-p1+1;
                    pr = {p1, i};
                }
                mpp2[s[p1]]--;
                if(mpp1.count(s[p1]) && mpp2[s[p1]] < mpp1[s[p1]]){
                    have--;
                }
                p1++;
            }
        }
        if(mini != INT_MAX) return s.substr(pr.first, mini);
        return  "";

    }
};
