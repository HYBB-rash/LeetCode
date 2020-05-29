/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 *
 * https://leetcode-cn.com/problems/water-and-jug-problem/description/
 *
 * algorithms
 * Medium (30.08%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 18.3K
 * Testcase Example:  '3\n5\n4'
 *
 * 有两个容量分别为 x升 和 y升 的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
 * 
 * 如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。
 * 
 * 你允许：
 * 
 * 
 * 装满任意一个水壶
 * 清空任意一个水壶
 * 从一个水壶向另外一个水壶倒水，直到装满或者倒空
 * 
 * 
 * 示例 1: (From the famous "Die Hard" example)
 * 
 * 输入: x = 3, y = 5, z = 4
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 输入: x = 2, y = 6, z = 5
 * 输出: False
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:

    bool canMeasureWater(int x, int y, int z) {
        int cap_a=0,cap_b=0;
        int max_a=min(x,y),max_b=max(x,y);
        cap_b=max_b;
        do{
            if(cap_a==z||cap_b==z||cap_a+cap_b==z) return true;
            if(cap_a==0&&cap_b!=0){
                if(cap_b>max_a){
                    cap_a=max_a;
                    cap_b-=max_a;
                }else{
                    cap_a=cap_b;
                    cap_b=0;
                }
            }
            else if(cap_b==0) cap_b=max_b;
            else if(cap_a==max_a) cap_a=0;
            else if(cap_a>0&&cap_a<max_a){
                int need=max_a-cap_a;
                if(need<=cap_b){
                    cap_b-=need;
                    cap_a=max_a;
                }else{
                    cap_a+=cap_b;
                    cap_b=0;
                }
            }

            
        }while(cap_a!=0||cap_b!=max_b);
        return false;
    }
};
// @lc code=end

