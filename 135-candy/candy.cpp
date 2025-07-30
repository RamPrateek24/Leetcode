class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        //left[0] = 1; 
        
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
        }
        int curr = 1, right = 1, sum = left[n-1];
        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                right++;
            }
            else{
                right = 1;
            }
            sum += max(left[i], right);
        }
        return sum;
    }
};