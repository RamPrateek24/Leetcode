class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        
        int n = fruits.size();

        vector<bool> left (n , false);
        for(int i = 0 ; i < n ; i++){
            int flag = false;
            for(int j = 0 ; j < n ; j++){
                if(!left[j] && baskets[j] >= fruits[i]){
                    left[j] = true;
                    flag = true;
                    break;
                }
            }
            if(flag) count++;
        }

        return fruits.size() - count;
    }
};
