class Solution {
public:
    vector<int> evenOddBit(int n) {
        string s = bitset<16>(n).to_string(); 
        reverse(s.begin(), s.end());        
        int e = 0, o = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {               
                if (i % 2 == 0) {
                    e++;                     
                } else {
                    o++;                     
                }
            }
        }

        return {e, o};                      
    }
};
