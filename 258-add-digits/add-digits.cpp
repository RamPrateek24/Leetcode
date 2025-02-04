class Solution {
public:
    int addDigits(int num) {
        int k,sum = 0;
        while(num){
           sum+= num%10;
           num /= 10;
        }
        if(sum > 9) return addDigits(sum);
        return sum;
    }
};