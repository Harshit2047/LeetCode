class Twitter {
public:
    vector<pair<int, int>> v;
    map<pair<int, int>, int> mp;
    Twitter() {
        mp.clear();
        v.clear();
    }
    void postTweet(int userId, int tweetId) { v.push_back({userId, tweetId}); }

    vector<int> getNewsFeed(int userId) {
        vector<int> temp;
        int count = 0;
        for (int i = v.size() - 1; i >= 0 && count < 10; i--) {
            if (mp.find({userId, v[i].first}) != mp.end()) {
                if (mp[{userId, v[i].first}] == 1){
                    temp.push_back(v[i].second);
                    count++;
                }
                    
            } else if (userId == v[i].first){
                temp.push_back(v[i].second);
                count++;
            }
                
        }
        return temp;
    }

    void follow(int followerId, int followeeId) {
    mp[{followerId, followeeId}] = 1;
}

void unfollow(int followerId, int followeeId) {
    mp[{followerId, followeeId}] = 0;
}

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */