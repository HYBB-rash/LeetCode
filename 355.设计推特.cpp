/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 *
 * https://leetcode-cn.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (36.62%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 10.2K
 * Testcase Example:  '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n' +
  '[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * 
 * 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：
 * 
 * 
 * postTweet(userId, tweetId): 创建一条新的推文
 * getNewsFeed(userId):
 * 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
 * follow(followerId, followeeId): 关注一个用户
 * unfollow(followerId, followeeId): 取消关注一个用户
 * 
 * 
 * 示例:
 * 
 * 
 * Twitter twitter = new Twitter();
 * 
 * // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
 * twitter.postTweet(1, 5);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
 * twitter.getNewsFeed(1);
 * 
 * // 用户1关注了用户2.
 * twitter.follow(1, 2);
 * 
 * // 用户2发送了一个新推文 (推文id = 6).
 * twitter.postTweet(2, 6);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
 * // 推文id6应当在推文id5之前，因为它是在5之后发送的.
 * twitter.getNewsFeed(1);
 * 
 * // 用户1取消关注了用户2.
 * twitter.unfollow(1, 2);
 * 
 * // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
 * // 因为用户1已经不再关注用户2.
 * twitter.getNewsFeed(1);
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
class Twitter
{
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<pair<int, int>>> twitter;
    unordered_map<int, unordered_map<int, bool>> Follow;
    int cnt_time = 0;
    Twitter()
    {
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        pair<int, int> temp(cnt_time++, tweetId);
        if (Follow[userId].empty())
            Follow[userId][userId] = true;
        twitter[userId].push_back(temp);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        if (Follow[userId].empty())
            Follow[userId][userId] = true;
        vector<pair<int, int>> tw;
        vector<int> ans;
        vector<int> follower;
        for (pair<int, bool> id : Follow[userId])
        {
            if (id.second == true)
                follower.push_back(id.first);
        }
        for (int id : follower)
        {
            for (pair<int, int> t : twitter[id])
            {
                tw.push_back(t);
            }
        }
        sort(tw.begin(), tw.end(), cmp);
        for (int i = 0; i < tw.size() && i < 10; i++)
        {
            ans.push_back(tw[i].second);
        }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (Follow[followerId].empty())
            Follow[followerId][followerId] = true;
        Follow[followerId][followeeId] = true;
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        if (Follow[followerId].empty())
            Follow[followerId][followerId] = true;
        if (followerId != followeeId)
            Follow[followerId][followeeId] = false;
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
// @lc code=end
