class Solution {
public:
    long long coloredCells(int n) {
        long long sum = 1;
        if(n==1) return 1;
        for(long long i=1; i<n; i++){
            sum+= (i*4);
        }
        return sum;
    }
};