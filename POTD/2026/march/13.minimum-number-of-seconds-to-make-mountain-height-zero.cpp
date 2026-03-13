class Solution {
private:
    long long find2(long long x) {
        return (-1 + pow(1 + 4 * x, 0.5)) / 2;
    }
    long long find(vector<int>& arr, long long sec) {
        long long height = 0; 
        for(auto& it : arr) {
            long long x = sec * 2 / it;
            height += find2(x);
        }
        return height;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0, r = 1e18;
        while(l <= r) {
            long long mid = (l + r) >> 1;
            long long height = find(workerTimes, mid);
            if(height >= mountainHeight) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};