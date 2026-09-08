class Solution {
public:
    long long countCommas(long long length) {
        long long commas = 0;

        if (length >= 1000) {
            long long end = min(length, 999999LL);
            commas += (end - 999) * 1;
        }

        if (length >= 1000000) {
            long long end = min(length, 999999999LL);
            commas += (end - 999999) * 2;
        }

        if (length >= 1000000000) {
            commas += (length - 999999999) * 3;
        }
        return commas;
    }
};