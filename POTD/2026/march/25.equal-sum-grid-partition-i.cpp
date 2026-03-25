class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> pre, post;
        long long sum = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                sum += grid[i][j];
            }
            pre.push_back(sum);
        }
        sum = 0;
        for(int i = grid.size() - 1; i >= 0; i--) {
            for(int j = grid[0].size() - 1; j >= 0; j--) {
                sum += grid[i][j];
            }
            post.push_back(sum);
        }
        reverse(post.begin(), post.end());
        for(int i = 0; i < pre.size() - 1; i++) {
            if(pre[i] == post[i+1])  return true;
        }
        vector<long long> pre2, post2;
        sum = 0;
        for(int i = 0; i < grid[0].size(); i++) {
            for(int j = 0; j < grid.size(); j++) {
                sum += grid[j][i];
            }
            pre2.push_back(sum);
        }
        sum = 0;
        for(int i = grid[0].size() - 1; i >= 0; i--) {
            for(int j = grid.size() - 1; j >= 0; j--) {
                sum += grid[j][i];
            }
            post2.push_back(sum);
        }
        reverse(post2.begin(), post2.end());
        for(int i = 0; i < pre2.size() - 1; i++) {
            if(pre2[i] == post2[i+1])  return true;
        }
        return false;
    }
};