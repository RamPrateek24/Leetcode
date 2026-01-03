class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<char, int> mpp1, mpp2;
        for(int i=0; i<s1.size(); i++) {
            mpp1[s1[i]]++;
           // mpp2[s2[i]]++;
        }
        int p1 = 0;
        for(int i=0; i<s2.size(); i++){
            mpp2[s2[i]]++;
            while(i - p1 + 1 > s1.size()){
                mpp2[s2[p1]]--;
                if(mpp2[s2[p1]] == 0) mpp2.erase(s2[p1]);
                p1++;
            }
            if(mpp1 == mpp2) return true;
        }
        return false;

    }
};
