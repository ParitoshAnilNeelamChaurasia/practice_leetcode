

class Solution {
public:
    int m , n ;

    int dp[1001][1001] ;
    int f(int ind1 , int ind2 , string text1 , string text2)
    {
        if(ind1 >= m || ind2 >= n)
        {
            return 0 ;
        }

        if(dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2] ;
        }

        if(text1[ind1] == text2[ind2])
        {
            return dp[ind1][ind2] = 1 + f(ind1+1,ind2+1 , text1,text2) ;
        }

        return dp[ind1][ind2] = max(f(ind1+1,ind2,text1,text2) , f(ind1 , ind2+1,text1,text2)) ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        m = text1.size() ;
        n = text2.size() ;

        memset(dp,-1,sizeof(dp)) ;

        return f(0,0,text1,text2) ;
    }
};
