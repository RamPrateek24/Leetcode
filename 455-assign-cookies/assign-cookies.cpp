class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int p1=0, p2=0, count=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(p2<m && p1<n){
            if(g[p1] <= s[p2]){
                p1++;
                p2++;
                count++;
            }
            else{
                p2++;
            }
        }
        return count;
    }
};