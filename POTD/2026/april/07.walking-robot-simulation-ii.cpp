class Robot {
int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
string dir_ans[4] = {"North", "East", "South", "West"};
int w, h, x = 0, y = 0, dir = 1, peri;
public:
    Robot(int width, int height) {
        w = width - 1; h = height - 1;
        peri = 2 * (w + h);
    }
    
    void step(int num) {
        num %= peri;
        if(num == 0) num = peri;
        while(num) {
            int x_ = x + num * direction[dir][0];
            int y_ = y + num * direction[dir][1];
            int steps = 0;
            if(y_ > h || y_ < 0) {
                if(y_ > h) {
                    steps = (h - y);
                    y = h;
                } else {
                    steps = y; y = 0;
                }
                dir = (dir + 3) % 4;
            } else if(x_ > w || x_ < 0) {
                if(x_ > w) {
                    steps = (w - x);
                    x = w;
                } else {
                    steps = x; x = 0;
                }
                dir = (dir + 3) % 4;
            } else {
                x = x_; y = y_; steps = num;
            }
            num -= steps;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dir_ans[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */