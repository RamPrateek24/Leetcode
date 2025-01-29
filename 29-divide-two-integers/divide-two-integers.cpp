class Solution {
public:
int divide(int dividend, int divisor) {
 
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;
    
  
    bool negative = (dividend < 0) ^ (divisor < 0);
    
    
    long long a = abs((long long)dividend);
    long long b = abs((long long)divisor);
    long long quotient = 0;
    
    
    while (a >= b) {
        long long temp = b, multiple = 1;
        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        a -= temp;
        quotient += multiple;
    }
    
    return negative ? -quotient : quotient;
}
};
