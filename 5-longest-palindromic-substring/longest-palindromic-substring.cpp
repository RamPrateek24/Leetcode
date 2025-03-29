class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return "";
        int maxx = 1;
        string z = s.substr(0, 1);
        for(int i=0; i<n; i++){
           // int count = 0;
            int p1 = i;
            int p2 = i + 1;
            while(p1>=0 && p2<n && s[p1]==s[p2]){
                if(s[p1]==s[p2]){
                   // count += 2;
                    p1--;
                    p2++;
                }
            }
            if(p2-p1-1 > maxx){
                maxx = p2-p1-1;
                z = s.substr(p1+1, p2-p1-1);
            }
             p1 = i-1;
             p2 = i+1;
            while(p1>=0 && p2<n && s[p1]==s[p2]){
                
                    //count += 2;
                    p1--;
                    p2++;
            }
            if(p2-p1-1>maxx){
                maxx = p2-p1-1;
                z = s.substr(p1+1, p2-p1-1);
            }
                
        }
        return z;
    }
};