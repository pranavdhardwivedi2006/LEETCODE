class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> arr(n); int ans = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0, j = m - 1;
            while(j >= 0 && !grid[i][j]) cnt++, j--;
            arr[i] = cnt;
        }
        for(int i = 0; i < n; i++) {
            if(arr[i] >= n - i - 1) continue ;
            int find = -1;
            for(int j = i + 1; j < n; j++) {
                if(arr[j] >= n - i - 1) {find = j; break;}
            }
            if(find == -1) return -1;
            while(find > i) {
                swap(grid[find], grid[find-1]);
                swap(arr[find], arr[find-1]); 
                ans++; find--;
            }
        }
        return ans;
    }
};