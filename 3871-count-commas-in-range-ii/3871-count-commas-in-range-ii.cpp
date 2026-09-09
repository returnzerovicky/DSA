class Solution {
public:
    long long countCommas(long long count) {
        long long commas = 0;

        if (count >= 1000LL) {
            long long end = min(count, 999999LL);
            commas += (end - 1000LL + 1) * 1;
        }

        if (count >= 1000000LL) {
            long long end = min(count, 999999999LL);
            commas += (end - 1000000LL + 1) * 2;
        }

        if (count >= 1000000000LL) {
            long long end = min(count, 999999999999LL);
            commas += (end - 1000000000LL + 1) * 3;
        }

        if (count >= 1000000000000LL) {
            long long end = min(count, 999999999999999LL);
            commas += (end - 1000000000000LL + 1) * 4;
        }

        if (count >= 1000000000000000LL) {
            long long end = min(count, 999999999999999999LL);
            commas += (end - 1000000000000000LL + 1) * 5;
        }

        return commas;
    }
};