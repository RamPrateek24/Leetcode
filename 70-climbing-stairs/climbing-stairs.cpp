class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
       int c = 0;
       int p1 = 1, p2 = 1;
       for(int i=2; i<=n; i++){
            c = p1+p2;
            p1 = p2;
            p2 = c;
       } 
       return c;
    }
};