class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curr = mass;
        sort(asteroids.begin(), asteroids.end());
        for(auto it : asteroids) {
            if(it <= curr) curr += it;
            else return false;
        }
        return true;
    }
};