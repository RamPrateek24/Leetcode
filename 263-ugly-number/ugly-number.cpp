class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        for( int ele : {2, 3, 5}){
            while(n%ele==0){
                n /= ele;
            }
        }
        return n==1;
    }
};