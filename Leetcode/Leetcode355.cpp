/*
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，
postTweet(userId, tweetId): 创建一条新的推文
getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
follow(followerId, followeeId): 关注一个用户
unfollow(followerId, followeeId): 取消关注一个用户

设计思路
用户类User：用户id,关注列表,推文链表
推文类Tweet：推文id,推文时间
用户池Userpool：map<id,用户>

postTweet(userId, tweetId): 创建一条新的推文
通过 Userpool 找到 User, 更新内部链表结构

getNewsFeed(userId):检索最近的十条推文。
通过 Userpool 找到 User，获取到用户的关注列表，提取所有推文，按时间倒序(优化方法：k路合并链表)

follow(followerId, followeeId): 关注一个用户
通过 Userpool 找到 User, 更新内部关注列表

unfollow(followerId, followeeId): 取消关注一个用户
通过 Userpool 找到 User, 更新内部关注列表
*/
# include<bits/stdc++.h>
using namespace std;
struct Tweet
{
    int time;
    int id;
    Tweet* next;
    Tweet(int a,int b,Tweet* node)
    {
        time = a;
        id = b;
        next = node;
    }
    /* data */
};
struct User
{
    int userid;
    unordered_map<int,int> fellowlist;
    User(int a)
    {
        userid = a;
    }
};

class Twitter{
    private:
        unordered_map<int,User*> Userpool;
        unordered_map<int,Tweet*> Tweetpool;
        int timeline;
    public:
        Twitter()
        {
            timeline = 0;
        }

        void postTweet(int userId,int tweetId)
        {
            // 没有用户
            if(Userpool.count(userId) == 0)
            {
                User* user = new User(userId);
                Userpool[userId] = user;
            }
            // 新建推文,更新推文池
            Tweet* head  = Tweetpool[userId];
            Tweet* tweet = new Tweet(timeline,tweetId,head);
            timeline++;
            Tweetpool[userId] = tweet;
        }

        vector<int> getNewsFeed(int userId){
            vector<int> res;
            vector< pair<int,int> > ans;
            if(Userpool.count(userId) == 0)
            {
                return res;
            }
            User* user = Userpool[userId];
            getallTweet(userId,ans);
            // 从用户的关注列表里面获取推文
            for(auto mm:user->fellowlist)
            {
                if(mm.second == 1)
                {
                    getallTweet(mm.first,ans);
                }    
            }
            sort(ans.rbegin(),ans.rend());
            int i = 0;
            while( i<10 && i<ans.size())
            {
                res.push_back(ans[i].second);
                i++;
            }
            return res;
        }

        void getallTweet(int userId,vector<pair<int,int> >& ans)
        {
            User* user = Userpool[userId];
            Tweet* tweet = Tweetpool[userId];
            Tweet* temp = tweet;
            while(temp)
            {
                ans.push_back(make_pair(temp->time,temp->id));
                temp = temp->next;
            }
        }


        void follow(int followerId, int followeeId)
        {
            if(followerId == followeeId)
            {
                return;
            }

            // 没有用户
            if(Userpool.count(followerId) == 0)
            {
                User* user1 = new User(followerId);
                Userpool[followerId] = user1;
            }

            // 没有用户
            if(Userpool.count(followeeId) == 0)
            {
                User* user2 = new User(followeeId);
                Userpool[followeeId] = user2;
            }
            
            

            User* user = Userpool[followerId];
            user->fellowlist[followeeId] = 1;
        }

        void unfollow(int followerId, int followeeId)
        {
            if(followerId == followeeId)
            {
                return;
            }
            // 没有用户
            if(Userpool.count(followerId) == 0)
            {
                User* user1 = new User(followerId);
                Userpool[followerId] = user1;
            }

            // 没有用户
            if(Userpool.count(followeeId) == 0)
            {
                User* user2 = new User(followeeId);
                Userpool[followeeId] = user2;
            }

            User* user = Userpool[followerId];
            user->fellowlist[followeeId] = 0;
        }

        void showflowList(int UserId)
        {
            User* user = Userpool[UserId];
            cout<<"User:"<<UserId<<" fellows:"<<endl;
            for(auto mm:user->fellowlist)
            {
                if(mm.second == 1)
                {
                    cout<<mm.first<<" "<<mm.second<<endl;
                }    
            }
        }

        void showTweetList(int UserId)
        {
            Tweet* tweet = Tweetpool[UserId];
            Tweet* temp = tweet;
            while(temp)
            {
                cout<<"time: "<<temp->time<<" tweetid: "<<temp->id<<endl;
                temp = temp->next;
            }
        }

};

int main()
{
    Twitter* tw = new Twitter();
    tw->postTweet(1,1);
    tw->follow(1,1);
    vector<int> res = tw->getNewsFeed(1);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
