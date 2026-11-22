class Solution {
public:
        long long maxDifference(vector<int>& A) {
        int n = A.size();
        long long dp2 = 0, dp1 = A[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            long long one = A[i] + (A[i] % 3 ? dp1 : -dp1);
            long long two = A[i] + A[i + 1] + ((A[i] + A[i + 1]) % 3 ? dp2 : -dp2);
            dp2 = dp1;
            dp1 = max(one, two);
        }
        return dp1;
    }
};