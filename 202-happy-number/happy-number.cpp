class Solution {
public:
    bool isHappy(int n) {
        //if(n==1) return true;
        //int sum = 0;
        unordered_set<int> seen;
        while(n!=1 && seen.find(n) == seen.end()){
            seen.insert(n);
            int sum = 0;
            while(n){
                sum += (n%10)*(n%10);
                n /= 10;
            }
            n = sum;
        } 
        return n == 1;
    }
};