/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int len=s.size();
        unordered_map<char,int> dic;
        int double_len=0;
        for(int i=0;i<len;i++){
            dic[s[i]]++;
        }
        pair<char,int> temp;
        bool flag=false;
        for(auto it=dic.begin();it!=dic.end();it++){
            temp=*it;
            if(temp.second%2==1){
                double_len+=temp.second-1;
                flag=true;
            }
            else{
                double_len+=temp.second;
            }
        }
        if(flag) return double_len+1;
        return double_len;
    }
};
// @lc code=end

