class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l = 0, r = 0, n1 = version1.size(), n2 = version2.size();
        while(l < n1 || r < n2) {
            string temp1 = "0", temp2 = "0";
            while(l < n1 && version1[l] != '.') temp1 += version1[l++];
            while(r < n2 && version2[r] != '.') temp2 += version2[r++];
            int k1 = stoi(temp1), k2 = stoi(temp2);
            if(k1 < k2) return -1;
            if(k1 > k2) return 1;
            l++, r++;
        } 
        return 0;
    }
};