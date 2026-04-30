struct comp {
    int side;
    comp(int s) {side = s;}
    long long calc(const vector<int>& temp) const {
        if(temp[1] == 0) return temp[0];
        if(temp[0] == side) return side + temp[1];
        if(temp[1] == side) return 3LL * side - temp[0];
        return 4LL * side - temp[1];
    }
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return calc(a) < calc(b);
    }
};

class Solution {
    bool isPossible(vector<vector<int>>& points, long long diff, int k, int side) {
        int n = points.size();
        vector<int> next(2 * n, -1);
        vector<long long> arr(2 * n);
        comp c(side);   
        for(int i = 0; i < n; i++) {
            arr[i] = c.calc(points[i]);
        }
        for(int i = 0; i < n; i++) {
            arr[i + n] = arr[i] + 4LL * side;
        }
        int l = 0, r = 0;
        while(l < 2 * n) {
            while(r < 2 * n && arr[r] - arr[l] < diff) {
                r++;
            }
            if(r < 2 * n) {
                next[l] = r;
            }
            l++;
        }
        for(int i = 0; i < n; i++) {
            int cnt = 1, curr = i;
            while(cnt < k) {
                curr = next[curr];
                if(curr == -1) break;
                if(curr >= i + n) break;
                cnt++;
            }
            if(cnt == k) {
                if(arr[i] + 4LL * side - arr[curr] >= diff) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        long long l = 0, r = 2LL * side; 
        sort(points.begin(), points.end(), comp(side));
        while(l <= r) {
            long long mid = (l + r) >> 1;
            bool possible = isPossible(points, mid, k, side);
            if(possible) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};