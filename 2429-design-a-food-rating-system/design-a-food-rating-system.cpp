class FoodRatings {
public:
    struct cmp {
    bool operator()(const pair<int,string> &a, const pair<int,string> &b) const {
        if(a.first != b.first) return a.first > b.first; 
        return a.second < b.second; 
    }
};
    unordered_map<string,set<pair<int,string>,cmp>> cuisine_rating;
    unordered_map<string,pair<int,string>> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            cuisine_rating[cuisines[i]].insert({ratings[i],foods[i]});
            food_rating[foods[i]]={ratings[i],cuisines[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating=food_rating[food].first;
        string corospodingCuisines=food_rating[food].second;
        food_rating[food].first=newRating;
        cuisine_rating[corospodingCuisines].erase({oldRating,food});
        cuisine_rating[corospodingCuisines].insert({newRating,food});
    }
    
    string highestRated(string cuisine) {
        return cuisine_rating[cuisine].begin()->second;

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */