class FoodRatings {

struct Comparator {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};

unordered_map<string, set<pair<int, string>, Comparator>> mpp; // cousines to {rating, food}
unordered_map<string, pair<int, string>> mpp2; // food to {rating, cousines}

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            mpp[cuisines[i]].insert({ratings[i], foods[i]});
            mpp2[foods[i]] = {ratings[i], cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [u, v] = mpp2[food];
        mpp2[food] = {newRating, v};
        mpp[v].erase({u, food}); 
        mpp[v].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return mpp.at(cuisine).begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */