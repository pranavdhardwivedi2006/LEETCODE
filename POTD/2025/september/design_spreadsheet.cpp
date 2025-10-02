class Spreadsheet {
vector<vector<int>> v;

public:
    Spreadsheet(int rows) {
        v.resize(rows + 1, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        int x = cell[0] - 'A';
        int y = 0;
        for (int i = 1; i < cell.size(); i++) {
            y *= 10;
            y += cell[i] - '0';
        }
        v[y][x] = value;
    }

    void resetCell(string cell) {
        int x = cell[0] - 'A';
        int y = 0;
        for (int i = 1; i < cell.size(); i++) {
            y *= 10;
            y += cell[i] - '0';
        }
        v[y][x] = 0;
    }

    int getValue(string formula) {
        int i = 1;
        string s;
        string str;
        while (formula[i] != '+') {
            s += formula[i];
            i++;
        }
        i++;
        while (i < formula.size()) {
            str += formula[i];
            i++;
        }
        int a, b;
        if (isalpha(s[0])) {
            int x = s[0] - 'A';
            int y = 0;
            for (int i = 1; i < s.size(); i++) {
                y *= 10;
                y += s[i] - '0';
            }
            a = v[y][x];
        } 
        else {
            int x = 0;
            for (int i = 0; i < s.size(); i++) {
                x *= 10;
                x += s[i] - '0';
            }
            a = x;
        }
        if (isalpha(str[0])) {
            int x = str[0] - 'A';
            int y = 0;
            for (int i = 1; i < str.size(); i++) {
                y *= 10;
                y += str[i] - '0';
            }
            b = v[y][x];
        } 
        else {
            int x = 0;
            for (int i = 0; i < str.size(); i++) {
                x *= 10;
                x += str[i] - '0';
            }
            b = x;
        }
        return a + b;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */