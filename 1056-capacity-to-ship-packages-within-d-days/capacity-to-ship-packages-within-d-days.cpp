class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), h = accumulate(weights.begin(), weights.end(), 0), mini = INT_MAX;
        while(l<=h){
            int mid = (l + h)/2;
            int  load = 0, dayss = 1;
            for(int i=0; i<weights.size(); i++){
                if(load + weights[i] > mid){
                    dayss += 1;
                    load = weights[i];
                }
                else{
                    load += weights[i];
                }
            }
            if(dayss <= days){
                mini= min(mini, mid);
                h = mid -1;
            }
            else{
                l = mid + 1;
            }
        }
        return mini;
    }
};