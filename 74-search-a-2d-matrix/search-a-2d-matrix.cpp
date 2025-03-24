class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0, h=rows-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(matrix[mid][0] < target) l = mid + 1;
            else if(matrix[mid][0] == target) return true;
            else h = mid - 1;
        } 
        if (h < 0) return false;
        auto z = lower_bound(matrix[h].begin(), matrix[h].end(), target);
        if (z != matrix[h].end() && *z == target) return true;
        return false;

    }
};