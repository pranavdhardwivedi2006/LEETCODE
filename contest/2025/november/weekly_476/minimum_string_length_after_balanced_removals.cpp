class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a = 0, b = 0;
        for(auto& it : s) {
            if(it == 'a') a++;
            else b++;
        }
        return abs(b - a);
    }
};