class Twitter {
    class tweet{
        public:
            int time;
            int userId;
            int tweetId;
            tweet(int t, int uid, int tid){
                time = t;
                userId = uid;
                tweetId = tid;
            }
    };
    class user {
        public:
            int userId;
            unordered_set<int> followers;
            unordered_set<int> following;
            vector<tweet *>myTweets;
            user(int id){
                userId=id;
            }
        };
    struct cmp{
        bool operator()(tweet *one, tweet *two){
            return one->time < two->time;
        }
    };
    unordered_map<int, user*> users;
    int time;
    void followSelf(int userId){
        if(!users.contains(userId)){
            users[userId] = new user(userId);
            users[userId]->following.insert(userId);
            users[userId]->followers.insert(userId); 
        }      
    }
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        user* curr = nullptr;
        followSelf(userId);
        curr = users[userId];
        tweet* mytweet = new tweet(time, userId, tweetId);
        curr->myTweets.push_back(mytweet);
    }
    
    vector<int> getNewsFeed(int userId) {
        followSelf(userId);
        vector<int> feed;
        user* curr = users[userId];
        priority_queue<tweet*, vector<tweet*>, cmp> recents;
        for(int it: curr->following){
            user* user = users[it];
            for(tweet* t : user->myTweets) recents.push(t);
        }
        while(!recents.empty() && feed.size()<10){
            feed.push_back(recents.top()->tweetId);
            recents.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        user* follower = nullptr;
        user* followee = nullptr;
        followSelf(followerId);
        followSelf(followeeId);
        if(followerId==followeeId) return;
        follower = users[followerId];
        followee = users[followeeId];
        follower->following.insert(followeeId);
        followee->followers.insert(followerId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        user* follower = nullptr;
        user* followee = nullptr;
        followSelf(followerId);
        followSelf(followeeId);
        if(followerId==followeeId) return;
        follower = users[followerId];
        followee = users[followeeId];
        follower->following.erase(followeeId);
        followee->followers.erase(followerId);
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