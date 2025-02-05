class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       // sort(s1.begin(), s1.end());
       // sort(s2.begin(), s2.end());
        int count = 0;
        if(s1 == s2) return true;
        vector<int> v;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                count++;
                v.push_back(i);
            }
        }
        return (count == 2 && s1[v[0]]== s2[v[1]] && s1[v[1]]== s2[v[0]]);
        
    }
};