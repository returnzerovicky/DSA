class Solution {
public:
    int minSetBits(vector<int>& nums, int k) {
        int n=nums.size(), m=n-k+1;
        vector<int> a(m), b(31, 0), s(m, 0);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<31; ++j)
                if(!(nums[i]>>j&1)) b[j]=i+1;
            if(i>=k-1) {
                int x=0;
                for(int j=0; j<31; ++j)
                    if(b[j]<=i-k+1) x |= 1<<j;
                if(!x) return -1;
                a[i-k+1]=x;
            }
        }
        int r=32;
        auto f=[&](auto& self, int i, int c) -> void{
            if(c>=r) return;
            while(i<m && s[i]) ++i;
            if(i==m) {
                r=c;
                return;
            }
            for(int j=0; j<31; ++j) {
                if(a[i] >> j & 1) {
                    vector<int> t;
                    for(int p=i; p<m; ++p)
                        if(!s[p] && (a[p] >> j & 1)) {
                            s[p] = 1;
                            t.push_back(p);
                        }
                    self(self, i+1, c+1);
                    for(int p : t) s[p] = 0;
                }
            }
        };
        f(f, 0, 0);
        return r;
    }
};