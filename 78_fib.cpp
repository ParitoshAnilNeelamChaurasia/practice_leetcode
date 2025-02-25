

class Solution {
public:
    int dp[31] ;
    int f(int n)
    {
        if(n <= 1)
        {
            return n ;
        }
        if(dp[n] != -1)
        {
            return dp[n] ;
        }

        return dp[n] = f(n-1) + f(n-2) ;
    }
    int fib(int n) {
        memset(dp,-1,sizeof(dp)) ;
        return f(n) ;
    }
};
