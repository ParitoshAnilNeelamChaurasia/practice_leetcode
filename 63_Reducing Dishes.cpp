

class Solution {
public:
    int n ;

    int dp[501][501] ;
    int f(int ind , int t ,vector<int> &satisfaction)
    {
        if(ind >= n)
        {
            return 0 ;
        }

        if(dp[ind][t] != -1)
        {
            return dp[ind][t] ;
        }

        
        int take = f(ind+1 , t+1 , satisfaction) + satisfaction[ind]*t ;

        int not_take = f(ind+1 , t , satisfaction) ;

        return dp[ind][t] = max(take,not_take) ;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size() ;

        sort(satisfaction.begin() , satisfaction.end()) ;
        memset(dp,-1,sizeof(dp)) ;

        bool flag = false ;
        for(auto it : satisfaction)
        {
            if(it < 0)
            flag = true ; break ;
        }

        // if(flag == false)
        // {
        //     int x = 0 ;
        //     for(int i = 0 ; i < n ; ++i)
        //     {
        //         x = x + satisfaction[i]*(i+1) ;
        //     }
        //     return x ;
        // }

        return f(0 , 1, satisfaction) ;
    }
};
