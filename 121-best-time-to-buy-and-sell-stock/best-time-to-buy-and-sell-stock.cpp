class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxx = INT_MIN, mini = INT_MAX;
        for(int i=0; i<n; i++){
            mini = min(mini, prices[i]);
            maxx = max(maxx, prices[i] - mini);
        }
        return maxx;
    }
};