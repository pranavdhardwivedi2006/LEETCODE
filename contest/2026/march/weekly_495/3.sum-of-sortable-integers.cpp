class Solution {
int check(int prev, int st, int k, vector<int>& arr) {
    int dip = 0, mini = arr[st], maxi = arr[st];
    for(int i = st; i + 1 < st + k; i++) {
        if(arr[i] > arr[i+1]) dip++;
        mini = min(mini, arr[i + 1]);
        maxi = max(maxi, arr[i + 1]);
    }
    if(dip == 0) return prev <= mini ? maxi : -1;
    if(dip == 1 && arr[st+k-1] <= arr[st]) return prev <= mini ? maxi : -1;
    return -1;
}
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> factors;
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                if(i != n / i) factors.push_back(i);
                factors.push_back(n / i);
            }
        }
        int ans = 0; 
        for(auto& it : factors) {
            bool isK = true; int prev = -1e9;
            for(int i = 0; i + it <= n; i += it) {
                prev = check(prev, i, it, nums);
                if(prev == -1) {
                    isK = false;
                    break;
                }
            }
            if(isK) ans += it;
        }
        return ans;
    }
};