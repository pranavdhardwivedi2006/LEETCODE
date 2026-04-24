class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0;
        for(auto& it : moves) {
            if(it == 'L') l--, r--;
            else if(it == 'R') l++, r++;
            else l--, r++;
        }
        return max(-l, r);
    }
};