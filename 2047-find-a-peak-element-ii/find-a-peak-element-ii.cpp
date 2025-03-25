class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, h = m-1;
        while(l<=h){
            int mid = (l+h)/2;
            int maxidx = -1;
            int maxval = -1;
            for(int i = 0; i<n; i++){
                if(mat[i][mid] > maxval){
                    maxval = mat[i][mid];
                    maxidx = i;
                }
            }
            int left = mid - 1 >=0 ? mat[maxidx][mid - 1] : -1;
            int right = mid + 1 < m ? mat[maxidx][mid+1] : -1;
            if(mat[maxidx][mid] > left && mat[maxidx][mid] > right){
                return {maxidx, mid};
            }
            else if(mat[maxidx][mid] < left){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return {-1, -1};
    }
};