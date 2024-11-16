// https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int dp[46] ;
    int f(int n)
    {
        if(n <= 2)
        {
            return n;
        }

        if(dp[n] != -1)
        {
            return dp[n] ;
        }

        return dp[n] = f(n-1) + f(n-2) ;
    }
    int climbStairs(int n) {

        memset(dp,-1,sizeof(dp)) ;
        return f(n) ;
    }
};
