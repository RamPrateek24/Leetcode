class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0, even = 1; 
        long long Sum = 0, result = 0;
        
        for (int num : arr) {
            Sum += num;

            if (Sum % 2 == 0) {
                result = (result + odd) % MOD; 
                even++;
            } else {
                result = (result + even) % MOD; 
                odd++;
            }
        }
        
        return result;
    }
};