class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i, a = ~0, m = 1e9; j < n; ++j)
                ans += ((a &= nums[j]) == (m = min(m, nums[j])));
        return ans;
    }
};