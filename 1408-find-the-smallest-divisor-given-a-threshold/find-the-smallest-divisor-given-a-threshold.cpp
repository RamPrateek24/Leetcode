class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxx = *max_element(nums.begin(), nums.end());
        int l = 1, h = maxx, mini = INT_MAX;
        while(l <= h){
            int mid = (h + l)/2;
            long long sum = 0;
            for(auto & el:nums){
                sum += ceil((double)el/mid);
            }
            if(sum > threshold){
                l = mid + 1;
            }
            else if(sum <= threshold){
                h = mid - 1;
                mini = min(mid, mini);
            }
        }
        return mini;
    }
};