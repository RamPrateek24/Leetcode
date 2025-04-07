class Solution {
public:
    bool func(vector<int> v, int total){
        vector<int> z;
        if(v.size() > 63) return false;  
        for(int i=0; i<(1LL<<(v.size())); i++){
            int sum = 0;
            for(int j = 0; j<v.size(); j++){
                if((i & (1LL<<j))){
                    sum += v[j];
                }
            }
            if(sum == total/2) return true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;

        int target = total / 2;
        unordered_set<int> sums = {0};

        for (int num : nums) {
            unordered_set<int> newSums;
            for (int s : sums) {
                int newSum = s + num;
                if (newSum == target) return true;
                newSums.insert(newSum);
            }
            for (int s : newSums) {
                sums.insert(s);
            }
        }

        return false;
    }
};