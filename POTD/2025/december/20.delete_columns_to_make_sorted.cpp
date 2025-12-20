#include <vector>
#include <string>   
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0, n = strs[0].size();
        for(int i = 0; i < n; i++) {
            int prev = 0;
            for(auto& it : strs) {
                if(prev > it[i]) {ans++; break;} 
                prev = it[i];
            }
        }
        return ans;
    }
};