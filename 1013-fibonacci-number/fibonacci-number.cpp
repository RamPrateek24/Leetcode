class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0; 
        if (n == 1) return 1; 
        int sum = 0, temp = 1;
        for (int i = 2; i <= n; i++) {
            int next = sum + temp; 
            sum = temp;            
            temp = next;           
        }

        return temp; 
    }
};
