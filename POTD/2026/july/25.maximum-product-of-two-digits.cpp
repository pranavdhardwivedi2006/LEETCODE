class Solution {
public:
    int maxProduct(int n) {
        vector<int> trk(10);
        while(n) {
            trk[n%10]++;
            n /= 10;
        }
        int cnt = 0, prod = 1;
        for(int i = 9; i >= 0; i--) {
            while(trk[i] && cnt != 2) {
                prod *= i;
                cnt++;
                trk[i]--;
            }
            if(cnt == 2) break;
        }
        return prod;
    }
};