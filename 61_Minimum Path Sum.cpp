

class Solution {
public:
    int m , n ;
    
    int dp[201][201] ;
    int f(int i , int j , vector<vector<int>>& grid)
    {
        if(i == m-1 && j == n-1)
        {
            return grid[m-1][n-1] ;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j] ;
        }

        int down = INT_MAX , right = INT_MAX ;
        if(i+1 < m)
        down = f(i+1 , j , grid) ;

        if(j+1 < n)
        right = f(i , j+1 , grid) ;
        
        return dp[i][j] = grid[i][j] + min(down , right) ;

    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size() ;
        n = grid[0].size() ;

        memset(dp,-1,sizeof(dp)) ;

        return f(0 , 0 , grid) ;
    }
};
