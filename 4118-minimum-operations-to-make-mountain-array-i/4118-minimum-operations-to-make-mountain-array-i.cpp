class Solution {
    // Make a[0..k-1] strictly increasing with every value >= 1, for every k.
    // cost[k]: fewest operations for the first k elements.
    // need[k]: the smallest value a[k] must reach to stand above them.
    static void climb(const vector<int>& a, vector<int>& cost, vector<int>& need) {
        int n = a.size();
        priority_queue<int> heap;          // shifted values w = a[i] - i
        int spent = 0;
        for (int i = 0; i < n - 1; ++i) {
            int w = a[i] - i;
            if (w < 1) {                   // a[i] can never go below i + 1
                spent += 1 - w;
                w = 1;
            }
            heap.push(w);
            if (heap.top() > w) {          // an earlier value sits too high
                spent += heap.top() - w;
                heap.pop();
                heap.push(w);
            }
            cost[i + 1] = spent;
            need[i + 1] = heap.top() + i + 1;
        }
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;

        vector<int> leftCost(n), leftNeed(n), rightCost(n), rightNeed(n);
        climb(nums, leftCost, leftNeed);
        vector<int> mirrored(nums.rbegin(), nums.rend());
        climb(mirrored, rightCost, rightNeed);

        int ans = INT_MAX;
        for (int p = 1; p < n - 1; ++p) {
            int r = n - 1 - p;             // elements to the right of the peak
            int height = max(leftNeed[p], rightNeed[r]);
            ans = min(ans, leftCost[p] + rightCost[r] + max(0, height - nums[p]));
        }
        return ans;
    }
};