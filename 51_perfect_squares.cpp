// https://leetcode.com/problems/perfect-squares/submissions/1454018845/

class Solution {
public:

    int dp[10001] ;
    int f(int n)
    {
        if(n == 0)
        {
            return 0 ;
        }

        if(dp[n] != -1)
        {
            return dp[n] ;
        }

        int mn = INT_MAX ;

        for(int i = 1 ; i*i <= n ; ++i)
        {
            int res = 1 + f(n-i*i) ;
            mn = min(mn,res) ;
        }
        return dp[n] = mn ;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp)) ;
        return f(n) ;
    }
};
