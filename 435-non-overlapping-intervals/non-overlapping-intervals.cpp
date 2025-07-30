class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({intervals[i][1], intervals[i][0]});
        }
        sort(v.begin(), v.end());
        int count = 0, ftime = v[0].first;
        for(int i=1; i<n; i++){
            if(v[i].second >= ftime){
                ftime = v[i].first;
            }
            else count++;
        }
        return count;
    }
};