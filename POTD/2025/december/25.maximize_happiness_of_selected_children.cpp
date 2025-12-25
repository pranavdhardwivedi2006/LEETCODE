class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0, curr = 0;
        priority_queue<int> pq(happiness.begin(), happiness.end());
        while(k--) {
            int x = pq.top(); pq.pop();
            if(x < curr) break;
            ans += x - curr++;
        }
        return ans;
    }
};