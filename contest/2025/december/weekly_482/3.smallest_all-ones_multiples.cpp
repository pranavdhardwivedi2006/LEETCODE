class Solution {
public:
    int minAllOneMultiple(int k) {
        set<int> rem;
        int num = 0, cnt = 0;
        while(1) {
            while(num < k) num = num * 10 + 1, cnt++;
            num %= k;
            if(num == 0) return cnt;
            if(rem.find(num) != rem.end()) return -1;
            rem.insert(num);
        }
        return -1;
    }
};