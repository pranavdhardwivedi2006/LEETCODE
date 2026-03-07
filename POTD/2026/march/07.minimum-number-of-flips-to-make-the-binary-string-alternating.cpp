class Solution {
int oo = 0, oz = 0, eo = 0, ez = 0;
private:
    int shift(string& s, int idx) {
        swap(oo, eo); swap(oz, ez);
        s[idx] == '0' ? oz-- : oo--;
        s[idx] == '0' ? ez++ : eo++;
        return min(oo + ez, oz + eo);
    }
public:
    int minFlips(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(i & 1) s[i] == '0' ? oz++ : oo++;
            else s[i] == '0' ? ez++ : eo++;
        }
        int cost = min(oo + ez, oz + eo);
        if(n & 1) {
            for(int i = 0; i < n; i++) {
                int x = shift(s, i);
                cost = min(cost, x);
            }
        }
        return cost;
    }
};