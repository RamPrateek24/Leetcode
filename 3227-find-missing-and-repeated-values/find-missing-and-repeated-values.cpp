class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), sum = 0;
        int m = grid[0].size();
        unordered_map<int, int> mpp;
        vector<int> v;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mpp[grid[i][j]]++;
            }
        }
        for( auto& el:mpp){
            if(el.second == 2) v.push_back(el.first);
            sum += el.first;
        }
        m = m*m;
        v.push_back((m*(m+1)/2) - sum);
        return v;
    }
};