class Solution {
int arr[26][26];
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                arr[i][j] = i == j ? 0 : -1;
            }
        }
        int n = original.size();
        for(int i = 0; i < n; i++) {
            int x = original[i]-'a';
            int y = changed[i]-'a';
            if(arr[x][y] == -1) arr[x][y] = cost[i];
            else arr[x][y] = min(arr[x][y], cost[i]);
        }
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(arr[i][k] == -1 || arr[k][j] == -1) continue;
                    if(arr[i][j] == -1) arr[i][j] = arr[i][k] + arr[k][j];
                    else arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            } 
        }
        long long ans = 0; n = source.size();
        for(int i = 0; i < n; i++) {
            if(arr[source[i]-'a'][target[i]-'a'] == -1) return -1;
            ans += arr[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};