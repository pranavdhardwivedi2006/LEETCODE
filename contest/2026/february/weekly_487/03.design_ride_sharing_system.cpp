class RideSharingSystem {
unordered_map<int, int> mpp, exist;
queue<int> rid, dri;
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rid.push(riderId);
        exist[riderId]++;
    }
    
    void addDriver(int driverId) {
        dri.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!rid.empty()) {
            int r = rid.front();
            if(mpp.find(r) != mpp.end()) {
                mpp[r]--; rid.pop(); exist.erase(r);
                if(mpp[r] == 0) mpp.erase(r);
            }
            else break;
        }
        if(rid.empty() || dri.empty()) return {-1, -1};
        int r = rid.front(), d = dri.front();
        rid.pop(); dri.pop(); exist.erase(r);
        return {d, r};
    }
    
    void cancelRider(int riderId) {
        if(exist.count(riderId)) mpp[riderId]++;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */