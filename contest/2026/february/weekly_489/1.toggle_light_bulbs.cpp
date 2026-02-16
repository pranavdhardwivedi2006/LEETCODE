class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> arr(101, 0), ans;
        for(auto it : bulbs) {
            arr[it] = !arr[it];
        }
        for(int i = 1; i <= 100; i++) 
            if(arr[i]) ans.push_back(i);
        return ans;
    }
};