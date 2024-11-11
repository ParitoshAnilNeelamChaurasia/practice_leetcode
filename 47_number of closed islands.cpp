

class Solution {
public:
    int m , n ;

    bool dfs(int i , int j , vector<vector<int>>& grid)
    {
        if(i >= m || i < 0 || j >= n || j < 0)
        {
            return false ;
        }

        if(grid[i][j] == 1)
        {
            return true ;
        }
        grid[i][j] = 1 ;

        bool left = dfs(i-1,j,grid) ;
        bool right = dfs(i+1,j,grid) ;
        bool down = dfs(i,j-1,grid) ;
        bool up = dfs(i,j+1,grid) ;

        return left && right && down && up ; 
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid[0].size() ;
        m = grid.size() ;

        int count = 0 ;

        for(int i = 0 ; i < m ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(grid[i][j] == 0)
                {
                    if(dfs(i,j,grid) == true)
                    {
                        count++ ;
                    }
                }
            }
        }
        return count ;
    }
};
