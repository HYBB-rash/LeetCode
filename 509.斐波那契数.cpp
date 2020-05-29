/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int N) {
        if(N == 0 || N == 1)
            return N;
        int a = fib(N - 1), b = fib(N - 2);
        return a + b;
    }
};
// @lc code=end

