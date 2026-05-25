class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), reached = 0;
        vector<bool> vis(n, false); 
        queue<int> q; q.push(0);
        vis[0] = true;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            if(node == n - 1) return true;
            int l = max(reached, node + minJump);
            int r = min(n - 1, node + maxJump);
            for(int i = l; i <= r; i++) {
                if(s[i] == '0' && !vis[i]) {
                    q.push(i);
                }
            }
            reached = max(reached, r + 1);
        }
        return false;
    }
};