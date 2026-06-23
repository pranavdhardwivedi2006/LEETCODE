class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int arr[26] = {0};
        for(auto it : text) arr[it-'a']++;
        return min({arr[0], arr[1], arr[11] / 2, arr[13], arr[14] / 2});
    }
};