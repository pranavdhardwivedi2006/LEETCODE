class track {
    int curr_dir = 0, x = 0, y = 0, dist = 0;
    set<pair<int, int>> obstacles;
public:
    track(vector<vector<int>>& obs) {
        for(auto& it : obs) obstacles.insert({it[0], it[1]});
    }

    void turn(int direction) {
        if(direction == -1) curr_dir = (curr_dir + 1) % 4;
        else curr_dir = (curr_dir + 3) % 4;
    }

    void move(int steps) {
        int factor = curr_dir > 1 ? -1 : 1;
        if(curr_dir & 1) {
            while(steps--) {
                auto it = make_pair(x + factor, y);
                if(obstacles.find(it) != obstacles.end()) break;
                x += factor;
            }
        } else {
            while(steps--) {
                auto it = make_pair(x, y + factor);
                if(obstacles.find(it) != obstacles.end()) break;
                y += factor;
            }
        }
        dist = max(dist, x * x + y * y);
    }

    int distance() {
        return dist;
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        track trk(obstacles);
        for(auto& it : commands) {
            if(it < 0) trk.turn(it);
            else trk.move(it);
        }
        return trk.distance();
    }
};