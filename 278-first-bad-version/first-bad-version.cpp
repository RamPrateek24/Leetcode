class Solution{
public:
    long long int firstBadVersion(long long int n) {
        long long int l = 1, r = n;
        while (l < r) {
            long long int mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
