class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, h = *min_element(ranks.begin(), ranks.end()) * (long long)cars * cars;
        long long mini = h;

        while (l < h) {
            long long mid = l + (h - l) / 2;
            long long tot = 0;

            for (int rank : ranks) {
                tot += sqrt(mid / rank);
            }

            if (tot >= cars) {
                mini = mid;
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return mini;
    }
};