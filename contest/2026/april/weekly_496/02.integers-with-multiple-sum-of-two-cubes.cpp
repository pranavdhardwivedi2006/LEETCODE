class Solution {
unordered_map<int, int> mpp;
int x = 0;
public:
    vector<int> findGoodIntegers(int n) {
        if(x == 0) {
            for(int i = 1; i <= 1000; i++) {
                for(int j = i; j <= 1000; j++) {
                    int p = i * i * i;
                    int q = j * j * j;
                    if(p + q > n) break;
                    mpp[p+q]++;
                }
            }
            x = 1;
        }
        vector<int> ans;
        for(auto& [u, v] : mpp) {
            if(u <= n && v > 1) ans.push_back(u);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};