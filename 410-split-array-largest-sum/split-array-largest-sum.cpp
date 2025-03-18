class Solution {
public:
    int count(vector<int>& v, int pages){
        int stu = 1;
        long long pagestu = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i] + pagestu <= pages){
                pagestu += v[i];
            }
            else{
                pagestu = v[i];
                stu += 1;
            }
        }
        return stu;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        while(l<=h){
            int mid = (l+h)/2;
            if(count(nums, mid) > k){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
     return l;   
    }
};