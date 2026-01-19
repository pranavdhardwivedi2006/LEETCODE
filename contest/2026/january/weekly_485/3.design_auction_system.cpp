class AuctionSystem {
map<pair<int, int>, int> mpp1;
map<int, set<pair<int, int>>> mpp2;
public:
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        auto it = make_pair(userId, itemId);
        if(mpp1.find(it) != mpp1.end()) {
            int x = mpp1[it];
            mpp2[itemId].erase({x, userId});
        }
        mpp1[it] = bidAmount;
        mpp2[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        auto it = make_pair(userId, itemId);
        int x = mpp1[it];
        mpp2[itemId].erase({x, userId});
        mpp2[itemId].insert({newAmount, userId});
        mpp1[it] = newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        auto it = make_pair(userId, itemId);
        int x = mpp1[it];
        mpp2[itemId].erase({x, userId});
        mpp1.erase(it);
    }
    
    int getHighestBidder(int itemId) {
        if(mpp2[itemId].empty()) return -1;
        auto it = mpp2[itemId].rbegin();
        return it -> second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */