class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for(auto it : digits) freq[it]++;
        int ans = 0;
        for(int i = 1; i <= 9; i++) {
            for(int j = 0; j <= 9; j++) {
                for(int k = 0; k < 9; k += 2) {
                    if(freq[i] && freq[j] > (i == j) && freq[k] > (i == k) + (j == k)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};